# New ports collection makefile for:	petsc
# Date created:		2012-04-08
# Whom:			Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
#
# $FreeBSD$
#

#############################################################################
# Add mercurial as dep?
# set optflags

#############################################################################
# Messages from dolfin:
# Solving nonlinear variational problem.
#   *** Warning: Using PETSc native LU solver. Consider configuring PETSc
# with an efficient LU solver (e.g. UMFPACK, MUMPS).
#
# ./demo_stokes-iterative 
# This demo is unlikely to converge if PETSc is not configured with the
# AMG preconditioners Hypre or ML.

PORTNAME=	petsc
PORTVERSION=	3.1
CATEGORIES=	math
MASTER_SITES=	http://ftp.mcs.anl.gov/pub/petsc/release-snapshots/
DISTNAME=	${PORTNAME}-${PORTVERSION}-p8

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

USE_LDCONFIG=	${PREFIX}/${PORTNAME}/lib

MAKE_ENV+=	PETSC_DIR=${WRKSRC}

# Added unzip,automake to work around make package-recursive failure

BUILD_DEPENDS=	${LOCALBASE}/lib/libsuperlu.a:${PORTSDIR}/math/superlu \
		svn:${PORTSDIR}/devel/subversion \
		${LOCALBASE}/bin/ar:${PORTSDIR}/devel/binutils \
		${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip \
		automake:${PORTSDIR}/devel/automake

#		${LOCALBASE}/lib/libBS95.a:${PORTSDIR}/math/blocksolve95 \

LIB_DEPENDS=	netcdf.4:${PORTSDIR}/science/netcdf

#		blacs:${PORTSDIR}/math/blacs \
#		--with-large-file-io=1 \	conftest fails
#		Shared lib build will fail if built with /usr/bin/ar

CONFIGURE_ARGS+=--prefix=${PREFIX}/${PORTNAME} \
		--CPPFLAGS=${CPPFLAGS} \
		--CFLAGS=${CFLAGS} \
		--CXXFLAGS=${CXXFLAGS} \
		--FFLAGS=${FFLAGS} \
		--LDFLAGS=${LDFLAGS} \
		--LD_SHARED=${FC} \
		--with-ar=${LOCALBASE}/bin/ar \
		--with-cpp=${CPP} \
		--with-cc=${CC} \
		--with-cxx=${CXX} \
		--with-fc=${FC} \
		--with-error-checking=yes \
		--with-language=C \
		--with-c++-support \
		--with-fortran=1 \
		--with-fortran-interfaces=1 \
		--with-pic=1 \
		--with-mpi=0

.include <bsd.port.pre.mk>

# 8.2 has issues with shared petsc lib
.if ${OSVERSION} > 802000
CONFIGURE_ARGS+=--with-shared=1
.endif

#############################################################################
# Trying to build with umfpack: (Need newer suitesparse?)
#
# umfpack.c: In function 'MatFactorInfo_UMFPACK':
# umfpack.c:296:94: error: 'UMFPACK_2BY2_TOLERANCE' undeclared
# (first use in this function)
# umfpack.c:296:94: note: each undeclared identifier is reported only once
# for each function it appears in
# umfpack.c: In function 'MatGetFactor_seqaij_umfpack':
# umfpack.c:427:45: error: 'UMFPACK_STRATEGY_2BY2' undeclared
# (first use in this function)
# umfpack.c:434:110: error: 'UMFPACK_2BY2_TOLERANCE' undeclared
# (first use in this function)

#		--with-umfpack=1 \
#		--with-umfpack-include="${LOCALBASE}/include/suitesparse" \
#		--with-umfpack-lib= \
#			[${LOCALBASE}/lib/libumfpack.so, \
#			${LOCALBASE}/lib/libamd.so, \
#			${LOCALBASE}/lib/libcholmod.so, \
#			${LOCALBASE}/lib/libcolamd.so] \

#############################################################################
# hypre, ml require MPI
#		--with-hypre=1 \
#		--with-ml=1 \

#############################################################################
# dolfin's petsc code uses int instead of PetscInt, so dolfin will not
# currently work with 64-bit petsc. (petsc defined PetscInt as int by default
# and long long if 64-bit indices are enabled)
#		--with-64-bit-indices=1 \
#		--with-64-bit-pointers=1 \
#		--with-mpi-dir=${LOCALBASE}/mpi/openmpi \
#		--with-mpiexec=${LOCALBASE}/mpi/openmpi/bin/mpirun \
#		--with-mpi-compilers=1 \

MAKEFILE=	makefile

CFLAGS+=	-O2
CXXFLAGS+=	-O2
FFLAGS+=	-O2
AR=		${LOCALBASE}/bin/ar

LIB_DEPENDS=	blas:${PORTSDIR}/math/blas \
		lapack:${PORTSDIR}/math/lapack

PFX=		${PORTNAME}
TARGET=		${OPSYS:L}
PLIST_SUB=	PFX=${PFX} TARGET=${TARGET}

pre-configure:
	${MKDIR} ${WRKSRC}/temp

.if ${OSVERSION} > 802000
post-install:
	${LN} ${PREFIX}/${PORTNAME}/lib/libpetsc.so \
		${PREFIX}/${PORTNAME}/lib/libpetsc.so.3
.endif

.include <bsd.port.post.mk>
