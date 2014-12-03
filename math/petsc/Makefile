# New ports collection makefile for:	petsc
# Date created:		2012-04-08
# Whom:			Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
#
# $FreeBSD$
#

# Note: -lpetsc-ufo... is supposed to fail in conftest

PORTNAME=	petsc
PORTVERSION=	3.5.2
CATEGORIES=	math
MASTER_SITES=	http://ftp.mcs.anl.gov/pub/petsc/release-snapshots/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Parallel solution of partial differential equations

HAS_CONFIGURE=	yes
USES=		gmake python perl5 fortran
USE_GCC=	yes
CONFIG_SHELL=	${PYTHONBIN}
CONFIGURE_LOG=	configure.log

MAKE_ENV+=	${CONFIGURE_ENV}

# PETSc automatically parallelizes compiles and rejects make -j
MAKE_JOBS_UNSAFE=	yes

BUILD_DEPENDS=	${LOCALBASE}/lib/libsuperlu.a:${PORTSDIR}/math/superlu \
		svn:${PORTSDIR}/devel/subversion

#		${LOCALBASE}/lib/libBS95.a:${PORTSDIR}/math/blocksolve95 \

LIB_DEPENDS=	libnetcdf.so:${PORTSDIR}/science/netcdf \
		libblas.so:${PORTSDIR}/math/blas \
		liblapack.so:${PORTSDIR}/math/lapack

#		blacs.1:${PORTSDIR}/math/blacs \

#		--LD_SHARED=${FC} \
#		--with-large-file-io=1 \	conftest fails
#		--with-c++-support \

CONFIGURE_ENV=	PETSC_DIR=${WRKSRC} \
		PETSC_ARCH=${OPSYS:L}

# PETSc build ignores the environment, so we have to pass everything to the
# configure script.
CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--doCleanup=0 \
		--with-clanguage=C \
		--with-fortran-interfaces \
		--with-proc-filesystem=0 \
		--with-cpp=${CPP} \
		--CPPFLAGS=${CPPFLAGS} \
		--with-cc=${CC} \
		--CFLAGS=${CFLAGS} \
		--with-cxx=${CXX} \
		--CXXFLAGS=${CXXFLAGS} \
		--with-fc=${FC} \
		--FFLAGS=${FFLAGS} \
		--LDFLAGS=-Wl,-rpath=${_GCC_RUNTIME} \
		--with-error-checking=yes \
		--with-debugger=gdb \
		--with-pic=1 \
		--with-mpi=0 \
		--with-mpi-dir=${LOCALBASE}/mpi/openmpi \
		--with-matlab=0 \
		--with-openmp=1 \
		--with-hwloc=1

MAKEFILE=	makefile

CONFIGURE_ARGS+=| tr '\r' '\n'

pre-configure:
	${MKDIR} ${WRKSRC}/temp
	find ${WRKSRC} -name '*.py' -exec sed -i '' 's|/usr/bin/python|/usr/bin/env python|g' '{}' \;

.include <bsd.port.mk>
