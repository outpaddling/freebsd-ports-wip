# Created by:	Jason Bacon
# $FreeBSD$

PORTNAME=	dolfin
PORTVERSION=	${MMVERSION}.0
CATEGORIES=	wip math python
MASTER_SITES=	http://launchpad.net/dolfin/${MMVERSION}.x/${MMVERSION}.0/+download/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C++/Python interface of FEniCS

LICENSE=	LGPL3

# Note: Currently can't tell if parmetis was built with openmpi or mpich2
# PETSc 3.4 fails PETSC_TEST_RUNS.  3.1 is rejected.  Use 3.2 or 3.3.
COMMON_DEPENDS=	${PYTHON_SITELIBDIR}/ufc_utils:math/ufc \
		${PYTHON_SITELIBDIR}/ffc:math/py-ffc \
		${PYTHON_SITELIBDIR}/FIAT:math/py-fiat \
		${PYTHON_SITELIBDIR}/instant:devel/py-instant \
		${PYTHON_SITELIBDIR}/ufl:math/py-ufl \
		${PYTHON_SITELIBDIR}/viper:math/py-viper \
		${PYTHON_SITELIBDIR}/numpy:math/py-numpy \
		${PYTHON_SITELIBDIR}/ply:devel/py-ply \
		swig3.0:devel/swig30 \
		sphinx-build:textproc/py-sphinx

BUILD_DEPENDS=	${COMMON_DEPENDS}

# Require MPI
#		${LOCALBASE}/lib/libscotch.a:wip/scotch
#		${LOCALBASE}/lib/parmetis/libparmetis.a:math/parmetis

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack \
		libamd.so:math/suitesparse \
		libumfpack.so:math/suitesparse \
		libcholmod.so:math/suitesparse \
		libboost_math_c99.so:devel/boost-libs \
		libCGAL.so:math/cgal \
		libxml2.so:textproc/libxml2 \
		libcppunit.so:devel/cppunit \
		libarmadillo.so:math/armadillo \
		libpetsc.so:science/PETSc

# Dolfin requires MPI if Trilinos is enabled
#		amesos:wip/trilinos
# Need better depend rule to ensure vtk5 is installed
RUN_DEPENDS=	${COMMON_DEPENDS}

USES=		cmake python:-2.7
USE_GCC=	any
PYDISTUTILS_PKGNAME=	dolfin
USE_LDCONFIG=	yes

# -- (**) PETSC		FreeBSD port broken
# -- (**) SLEPC		Extension of PETSc
# -- (**) MTL4		Parallel version is commercial

# FIXME: Check CMakeCache.txt for anything defaulting to work directory
# like CHOLMOD_DIR
# CHOLMOD and UMFPACK must be defined for FreeBSD 8.2 stock ports
# Presumably Find*.cmake scripts require cmake > 2.8.3
# PETSC_ARCH should be unset when using an installed petsc
# https://answers.launchpad.net/dolfin/+question/170317
# Trilinos, scotch, parmetis, slepc require MPI
CMAKE_ARGS+=	-DDOLFIN_ENABLE_MPI:BOOL=OFF \
		-DDOLFIN_ENABLE_SLEPC:BOOL=OFF \
		-DDOLFIN_ENABLE_TRILINOS:BOOL=OFF \
		-DDOLFIN_ENABLE_PARMETIS:BOOL=OFF \
		-DDOLFIN_ENABLE_SCOTCH:BOOL=OFF \
		-DDOLFIN_ENABLE_MTL4:BOOL=OFF \
		-DDOLFIN_ENABLE_PETSC:BOOL=ON \
		-DDOLFIN_MAN_DIR:PATH=man \
		-DPETSC_DIR:PATH=${LOCALBASE} \
		-DCHOLMOD_DIR:PATH=${LOCALBASE} \
		-DUMFPACK_DIR:PATH=${LOCALBASE} \
		-DDOLFIN_PKGCONFIG_DIR:PATH=${LOCALBASE}/libdata/pkgconfig

# Trilinos requires MPI
#		-DZoltan_DIR:PATH=${LOCALBASE}/trilinos/lib/cmake/Zoltan \
#		-DML_DIR:PATH=${LOCALBASE}/trilinos/lib/cmake/ML \
#		-DIfpack_DIR:PATH=${LOCALBASE}/trilinos/lib/cmake/Ifpack \
#		-DAmesos_DIR:PATH=${LOCALBASE}/trilinos/lib/cmake/Amesos \
#		-DEpetra_DIR:PATH=${LOCALBASE}/trilinos/lib/cmake/Epetra \

FETCH_ARGS=	-F

MMVERSION=	1.2

post-patch:
	${REINPLACE_CMD} -e 's|os.path.join(os.path.sep,"usr")|os.path.normpath("${PREFIX}")|' ${WRKSRC}/site-packages/dolfin/compilemodules/compilemodule.py
	${REINPLACE_CMD} -e "s|/usr/local/lib/petsc|${LOCALBASE}|" ${WRKSRC}/cmake/modules/FindPETSc.cmake
	${REINPLACE_CMD} -e 's|$${PETSC_ARCH}/include|include|' ${WRKSRC}/cmake/modules/FindPETSc.cmake

.include <bsd.port.mk>
