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

# Custom configure script, not GNU
HAS_CONFIGURE=	yes
USES=		gmake python perl5 fortran
USE_GCC=	yes
CONFIG_SHELL=	${PYTHONBIN}
CONFIGURE_LOG=	configure.log

# PETSc automatically parallelizes compiles and rejects make -j
MAKE_JOBS_UNSAFE=	yes

BUILD_DEPENDS=	${LOCALBASE}/lib/libsuperlu.a:${PORTSDIR}/math/superlu \
		svn:${PORTSDIR}/devel/subversion

LIB_DEPENDS=	libnetcdf.so:${PORTSDIR}/science/netcdf \
		libblas.so:${PORTSDIR}/math/blas \
		liblapack.so:${PORTSDIR}/math/lapack

CONFIGURE_ENV=	PETSC_DIR=${WRKSRC} \
		PETSC_ARCH=${OPSYS:tl} \

USE_LDCONFIG=	${PREFIX}/petsc/lib

# PETSc's configure ignores the environment, so we have to pass everything
# to the configure script.
CONFIGURE_ARGS+=--prefix=${PREFIX}/petsc \
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
		--with-debugger=gdb \
		--with-pic=1 \
		--with-mpi=1 \
		--with-matlab=0

# Show all build output instead of overwriting the same line
CONFIGURE_ARGS+=| tr '\r' '\n'

CC=		${PREFIX}/mpi/openmpi/mpicc
CXX=		${PREFIX}/mpi/openmpi/mpicxx
FC=		${PREFIX}/mpi/openmpi/mpif90

MAKEFILE=	makefile
MAKE_ENV+=	${CONFIGURE_ENV}

# PETSc appears to be using DESTDIR like PREFIX.  It's set to ${PREFIX}
# by PETSc's configure script, but then overridden by ports to
# ${WRKSRC}/stage, resulting in a real install prefix of '/'. Adding
# DESTDIR=${STAGEDIR}${PREFIX} to the default INSTALL_TARGET fixes the problem.
INSTALL_TARGET=	DESTDIR=${STAGEDIR}${PREFIX}/petsc \
		PETSC_DIR=/usr/wip/math/petsc/work/petsc-3.5.2 \
		PETSC_ARCH=freebsd \
		install

# FIXME: shebang_fix?
pre-configure:
	${MKDIR} ${WRKSRC}/temp
	find ${WRKSRC} -name '*.py' -exec \
		sed -i '' 's|/usr/bin/python|/usr/bin/env python|g' '{}' \;

.include <bsd.port.mk>
