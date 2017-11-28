# New ports collection makefile for:	petsc
# Date created:		2012-04-08
# Whom:			Jason Bacon <jwb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	petsc
PORTVERSION=	3.3
CATEGORIES=	wip math
MASTER_SITES=	http://ftp.mcs.anl.gov/pub/petsc/release-snapshots/
DISTNAME=	${PORTNAME}-${PORTVERSION}-p7

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Parallel solution of partial differential equations

HAS_CONFIGURE=	yes
USES=		perl5 python fortran gmake
CONFIG_SHELL=	${PYTHONBIN}
CONFIGURE_LOG=	configure.log

USE_LDCONFIG=	yes

CONFIGURE_ENV=	PETSC_DIR=${WRKSRC} \
		PETSC_ARCH=${OPSYS:L}

MAKE_ENV+=	${CONFIGURE_ENV}

BUILD_DEPENDS=	${LOCALBASE}/lib/libsuperlu.a:math/superlu \
		svn:devel/subversion
#		${LOCALBASE}/lib/libBS95.a:math/blocksolve95 \

LIB_DEPENDS=	libnetcdf.so:science/netcdf \
		libblas.so:math/blas \
		liblapack.so:math/lapack


#		blacs.1:math/blacs \

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
		--with-mpi=0 \
		--with-matlab=0

MAKEFILE=	makefile

CONFIGURE_ARGS+=	| tr '\r' '\n'

pre-configure:
	${MKDIR} ${WRKSRC}/temp

post-install:
	${LN} -s ${PREFIX}/lib/libpetsc.so ${PREFIX}/lib/libpetsc.so.3

.include <bsd.port.mk>
