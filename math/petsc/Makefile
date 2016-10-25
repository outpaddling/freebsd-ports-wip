# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$
# Note: -lpetsc-ufo... is supposed to fail in conftest

PORTNAME=	petsc
PORTVERSION=	3.7.4
CATEGORIES=	math
MASTER_SITES=	http://ftp.mcs.anl.gov/pub/petsc/release-snapshots/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Parallel solution of partial differential equations

LICENSE=	BSD2CLAUSE

# LIB_DEPENDS=	svn:devel/subversion
LIB_DEPENDS=	libsuperlu.so:math/superlu \
		libnetcdf.so:science/netcdf \
		libblas.so:math/blas \
		liblapack.so:math/lapack \
		libscalapack.so:math/scalapack

# Custom configure script, not GNU
HAS_CONFIGURE=	yes
USES=		gmake python perl5 fortran
USE_GCC=	yes
CONFIG_SHELL=	${PYTHONBIN}
CONFIGURE_LOG=	configure.log

# PETSc automatically parallelizes compiles and rejects make -j
MAKE_JOBS_UNSAFE=	yes

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
		--with-mpi=0 \
		--with-matlab=0

# Show all build output instead of overwriting the same line
CONFIGURE_ARGS+=| ${TR} '\r' '\n'

MAKEFILE=	makefile
MAKE_ENV+=	${CONFIGURE_ENV}

# PETSc appears to be using DESTDIR like PREFIX.  It's set to ${PREFIX}
# by PETSc's configure script, but then overridden by ports to
# ${WRKSRC}/stage, resulting in a real install prefix of '/'. Adding
# DESTDIR=${STAGEDIR}${PREFIX} to the default INSTALL_TARGET fixes the problem.
INSTALL_TARGET=	DESTDIR=${STAGEDIR}${PREFIX}/petsc \
		PETSC_DIR=${WRKSRC} \
		PETSC_ARCH=freebsd \
		install

# FIXME: Test this
# INSTALL_TARGET=	install-strip

# FIXME: shebang_fix?
pre-configure:
	${MKDIR} ${WRKSRC}/temp
	@${FIND} ${WRKSRC} -name '*.py' -exec \
		${SED} -i '' 's|/usr/bin/python|/usr/bin/env python|g' '{}' \;

# make test?

.include <bsd.port.mk>
