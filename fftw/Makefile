# New ports collection makefile for: fftw
# Date created:		Dec 28 1998
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $FreeBSD: ports/math/fftw/Makefile,v 1.48 2012/11/17 05:59:20 svnexp Exp $
#

PORTNAME=	fftw
PORTVERSION=	2.1.5
PORTREVISION?=	6
CATEGORIES=	wip math
MASTER_SITES=	ftp://ftp.fftw.org/pub/fftw/ 		\
		ftp://ftp.fftw.org/pub/fftw/old/ 	\
		ftp://theory.lcs.mit.edu/pub/fftw/	\
		ftp://pm.cse.rmit.edu.au/pub/dsp/fftw/
PKGNAMESUFFIX=	${FFTW_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Fast C routines to compute the Discrete Fourier Transform

LICENSE=	GPLv2

# current flavors: default, float
FFTW_FLAVOR?=	default
FFTW_SUFIX=

USE_FORTRAN=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal automake autoconf libtool
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--enable-shared
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

PLIST_SUB=	FFTW_SUFX="${FFTW_SUFX}"
PLIST=		${.CURDIR}/pkg-plist

PORTSCOUT=	limit:^2\.

.include <bsd.port.pre.mk>

.if ${FFTW_FLAVOR}=="float"
CONFIGURE_ARGS+=	--enable-float --enable-type-prefix
FFTW_SUFX=		s
FFTW_PKGNAMESUFFIX=	-float
PLIST_SUB+=	DEF="@comment "
.else
.if !defined(WITH_OPENMPI) && !defined(WITH_MPICH)
INFO=			fftw
.endif
PLIST_SUB+=	DEF=""
.endif

# Allow slave ports to override
GNU_CONFIGURE_PREFIX?=	${PREFIX}

# Note to ports base developers: It would be useful to be able to override
# --mandir and --infodir, which have default values separate from
# GNU_CONFIGURE_PREFIX.

.if defined(WITH_OPENMPI)
MPIDIR=			mpi/openmpi
MPI_LOCALBASE=		${LOCALBASE}/${MPIDIR}
GNU_CONFIGURE_PREFIX=	${PREFIX}/${MPIDIR}
DOCSDIR=		${GNU_CONFIGURE_PREFIX}/share/doc/${PORTNAME}
INFO_PATH=		${MPIDIR}/info
FFTW_PKGNAMESUFFIX=	-openmpi
CONFIGURE_ARGS+=	--enable-mpi
CC=			${LOCALBASE}/${MPIDIR}/bin/mpicc
# Using LIB_DEPENDS=mpi could detect the wrong MPI implementation.
BUILD_DEPENDS+=		${MPI_LOCALBASE}/lib/libmpi.so:net/openmpi
RUN_DEPENDS+=		${MPI_LOCALBASE}/lib/libmpi.so:net/openmpi
CFLAGS+=		-I${MPI_LOCALBASE}/include
LDFLAGS+=		-L${MPI_LOCALBASE}/lib -L${LOCALBASE}/lib
.endif

.if defined(WITH_MPICH)
GNU_CONFIGURE_PREFIX=	${PREFIX}/mpi/mpich
DOCSDIR=		${GNU_CONFIGURE_PREFIX}/share/doc/${PORTNAME}
INFO_PATH=		mpi/mpich/info
FFTW_PKGNAMESUFFIX=	-mpich
CONFIGURE_ARGS+=	--enable-mpi
CC=			${LOCALBASE}/bin/mpicc
LIB_DEPENDS+=		mpich:net/mpich2
.endif

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-i386-hacks
.endif

.if ${ARCH} == "sparc64"
BROKEN=		does not build
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc | |' ${WRKSRC}/Makefile.am

post-build:
.if ${FFTW_FLAVOR}=="default"
	@cd ${WRKSRC}/doc && makeinfo fftw.texi
.endif

.if defined(WITH_OPENMPI) || defined(WITH_MPICH)
do-install:
	${MKDIR} ${GNU_CONFIGURE_PREFIX}/lib ${GNU_CONFIGURE_PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/mpi/*fftw*_mpi.h \
			${GNU_CONFIGURE_PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/mpi/lib*fftw_mpi* \
			${GNU_CONFIGURE_PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/mpi/.libs/lib*fftw_mpi* \
			${GNU_CONFIGURE_PREFIX}/lib
.endif
	
.if !defined(WITH_OPENMPI) && !defined(WITH_MPICH)
post-install:
.if ${FFTW_FLAVOR}=="default"
	${MKDIR} ${PREFIX}/${INFO_PATH}
	${INSTALL_DATA} ${WRKSRC}/doc/fftw.info ${PREFIX}/${INFO_PATH}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/fftw.ps ${DOCSDIR}/fftw.ps
.endif
.endif
.endif

do-configure:
	echo $$MAKEINFO

regression-test: build
	@cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>
