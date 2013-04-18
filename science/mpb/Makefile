# ex:ts=8
# Ports collection makefile for:	mpb
# Date created:			Apr 4, 2003
# Whom:				ijliao
#
# $FreeBSD: ports/science/mpb/Makefile,v 1.20 2011/11/22 11:14:09 bf Exp $
#

PORTNAME=	mpb
PORTVERSION=	1.4.2
PORTREVISION=	11
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/mpb/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIT Photonic-Bands

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	fftw:${PORTSDIR}/math/fftw \
		hdf5.7:${PORTSDIR}/science/hdf5-18 \
		ctl.4:${PORTSDIR}/science/libctl \
		guile.21:${PORTSDIR}/lang/guile
USE_FORTRAN=	yes

.include <bsd.port.pre.mk>
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-DH5_USE_16_API
LDFLAGS+=	-L${LOCALBASE}/lib

# Don't do things behind the user's back
# Use slave-port for atlas version
#.if exists(${LOCALBASE}/lib/libatlas.so) && !defined(WITH_BLAS)
#WITH_ATLAS=	yes
#.endif

.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
CONFIGURE_ARGS+=	--with-lapack=-lalapack --program-suffix=-atlas
PKGNAMESUFFIX=	-atlas
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
CONFIGURE_ARGS+=	--with-lapack=-llapack
.endif

.if defined(WITH_OPENMPI)
MPIDIR=			mpi/openmpi
PKGNAMESUFFIX=		-openmpi
MPI_LOCALBASE=		${LOCALBASE}/${MPIDIR}
# LIB_DEPENDS=fftw_mpi might detect mpich2 or other implementation
BUILD_DEPENDS+=		${MPI_LOCALBASE}/lib/libfftw_mpi.so:../../math/fftw${PKGNAMESUFFIX}
RUN_DEPENDS+=		${MPI_LOCALBASE}/lib/libfftw_mpi.so:../../math/fftw${PKGNAMESUFFIX}
CONFIGURE_ARGS+=	--with-mpi
.elif defined(WITH_MPICH)
MPIDIR=			mpi/mpich
PKGNAMESUFFIX=		-mpich
# Hopefully ${LOCALBASE}/${MPIDIR} in the future
MPI_LOCALBASE=		${LOCALBASE}
# LIB_DEPENDS=fftw_mpi might detect mpich2 or other implementation
BUILD_DEPENDS+=		${MPI_LOCALBASE}/lib/libfftw_mpi.so:../../math/fftw${PKGNAMESUFFIX}
RUN_DEPENDS+=		${MPI_LOCALBASE}/lib/libfftw_mpi.so:../../math/fftw${PKGNAMESUFFIX}
CONFIGURE_ARGS+=	--with-mpi
.endif

GNU_CONFIGURE_PREFIX=	${PREFIX}/${MPIDIR}
FC=			${MPI_LOCALBASE}/bin/mpif90
CPPFLAGS+=		-I${MPI_LOCALBASE}/include
LDFLAGS+=		-L${MPI_LOCALBASE}/lib

MAN1=	mpb.1

.if !defined(WITH_OPENMPI)
MAN1+=	mpb-data.1 mpb-split.1
.endif

PLIST=	${.CURDIR}/pkg-plist

post-patch:
	@${REINPLACE_CMD} \
		-e 's|-lhdf5 |-lhdf5 ${PTHREAD_LIBS} |g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
