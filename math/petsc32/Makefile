# New ports collection makefile for:	petsc
# Date created:		2012-04-08
# Whom:			Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	petsc
PORTVERSION=	3.2
CATEGORIES=	math
MASTER_SITES=	http://ftp.mcs.anl.gov/pub/petsc/release-snapshots/
DISTNAME=	${PORTNAME}-${PORTVERSION}-p7

MAINTAINER=	jwbacon@tds.net
COMMENT=	Parallel solution of partial differential equations

HAS_CONFIGURE=	yes
USE_PERL5=	yes
USE_PYTHON=	yes
USE_FORTRAN=	yes
CONFIG_SHELL=	${PYTHONBIN}
CONFIGURE_LOG=	configure.log

CONFIGURE_ENV=	PETSC_ARCH=${OPSYS:L} \
		PETSC_DIR=${WRKSRC}

MAKE_ENV+=	PETSC_DIR=${WRKSRC} \
		PETSC_ARCH=${OPSYS:L}

BUILD_DEPENDS=	${LOCALBASE}/lib/libsuperlu.a:${PORTSDIR}/math/superlu \
		svn:${PORTSDIR}/devel/subversion \
		svn:${PORTSDIR}/devel/subversion
#		${LOCALBASE}/lib/libBS95.a:${PORTSDIR}/math/blocksolve95 \

LIB_DEPENDS=	netcdf.4:${PORTSDIR}/science/netcdf

#		blacs.1:${PORTSDIR}/math/blacs \

#		--LD_SHARED=${FC} \
#		--with-large-file-io=1 \	conftest fails
#		--with-c++-support \

CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--CPPFLAGS=${CPPFLAGS} \
		--CFLAGS=${CFLAGS} \
		--CXXFLAGS=${CXXFLAGS} \
		--FFLAGS=${FFLAGS} \
		--LDFLAGS=${LDFLAGS} \
		--with-cpp=${CPP} \
		--with-cc=${CC} \
		--with-cxx=${CXX} \
		--with-fc=${FC} \
		--with-error-checking=yes \
		--with-language=C \
		--with-fortran \
		--with-fortran-interfaces \
		--with-debugger=gdb \
		--with-shared-libraries=1 \
		--with-64-bit-indices=1 \
		--with-64-bit-pointers=1 \
		--with-pic \
		--with-mpi=0

MAKEFILE=	makefile

CFLAGS+=	-O
CXXFLAGS+=	-O
FFLAGS+=	-O

LIB_DEPENDS=	blas:${PORTSDIR}/math/blas \
		lapack:${PORTSDIR}/math/lapack

pre-configure:
	${MKDIR} ${WRKSRC}/temp

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
