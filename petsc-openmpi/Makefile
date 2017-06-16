# New ports collection makefile for:	petsc
# Date created:		2012-04-08
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

# Note: -lpetsc-ufo... is supposed to fail in conftest

PORTNAME=	petsc
PORTVERSION=	3.5.2
PKGNAMESUFFIX=	-openmpi
# Conflict with petsc on ldconfig
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
CATEGORIES=	wip math
MASTER_SITES=	http://ftp.mcs.anl.gov/pub/petsc/release-snapshots/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Parallel solution of partial differential equations

# Custom configure script, not GNU
HAS_CONFIGURE=	yes
USES=		gmake python perl5 fortran
USE_GCC=	yes
CONFIG_SHELL=	${PYTHONBIN}
CONFIGURE_LOG=	configure.log

CONFLICTS=	mpich2

# PETSc automatically parallelizes compiles and rejects make -j
MAKE_JOBS_UNSAFE=	yes

# Mumps requires scalapack, which requires either mpich2 or openmpi
# Need a mumps-openmpi slave port?
BUILD_DEPENDS=	${LOCALBASE}/lib/libsuperlu.a:math/superlu \
		${LOCALBASE}/lib/libmumps_common.a:math/mumps \
		svn:devel/subversion

LIB_DEPENDS=	libnetcdf.so:science/netcdf \
		libblas.so:math/blas \
		liblapack.so:math/lapack

CONFIGURE_ENV=	PETSC_DIR=${WRKSRC} \
		PETSC_ARCH=${OPSYS:tl} \

USE_LDCONFIG=	${PREFIX}/petsc${PKGNAMESUFFIX}/lib

# PETSc's configure ignores the environment, so we have to pass everything
# to the configure script.
CONFIGURE_ARGS+=--prefix=${PREFIX}/petsc${PKGNAMESUFFIX} \
		--doCleanup=0 \
		--with-clanguage=C \
		--with-fortran-interfaces \
		--with-proc-filesystem=0 \
		--CPPFLAGS=${CPPFLAGS} \
		--CFLAGS=${CFLAGS} \
		--CXXFLAGS=${CXXFLAGS} \
		--FFLAGS=${FFLAGS} \
		--LDFLAGS=-Wl,-rpath=${_GCC_RUNTIME} \
		--with-debugger=gdb \
		--with-pic=1 \
		--with-mpi=1 \
		--with-mpi-dir=${PREFIX}/mpi/openmpi \
		--with-matlab=0 \
		--with-mumps=1 \
		--with-scalapack=1

# Show all build output instead of overwriting the same line
CONFIGURE_ARGS+=| tr '\r' '\n'

# No effect
#CC=		${PREFIX}/mpi/openmpi/mpicc
#CXX=		${PREFIX}/mpi/openmpi/mpicxx
#FC=		${PREFIX}/mpi/openmpi/mpif90

MAKEFILE=	makefile
MAKE_ENV+=	${CONFIGURE_ENV}

# PETSc appears to be using DESTDIR like PREFIX.  It's set to ${PREFIX}
# by PETSc's configure script, but then overridden by ports to
# ${WRKSRC}/stage, resulting in a real install prefix of '/'. Adding
# DESTDIR=${STAGEDIR}${PREFIX} to the default INSTALL_TARGET fixes the problem.
INSTALL_TARGET=	DESTDIR=${STAGEDIR}${PREFIX}/petsc${PKGNAMESUFFIX} \
		PETSC_DIR=${WRKSRC} \
		PETSC_ARCH=freebsd \
		install

# FIXME: shebang_fix?
pre-configure:
	${MKDIR} ${WRKSRC}/temp
	find ${WRKSRC} -name '*.py' -exec \
		sed -i '' 's|/usr/bin/python|/usr/bin/env python|g' '{}' \;

.include <bsd.port.mk>
