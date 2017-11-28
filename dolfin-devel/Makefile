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
# Leave paths as ../../ instead of ${PORTSDIR} until committed for
# development purposes
# PETSc 3.4 fails PETSC_TEST_RUNS.  3.1 is rejected.  Use 3.2 or 3.3.
COMMON_DEPENDS=	${PYTHON_SITELIBDIR}/ufc_utils:../../math/ufc \
		${PYTHON_SITELIBDIR}/ffc:../../math/py-ffc \
		${PYTHON_SITELIBDIR}/FIAT:../../math/py-fiat \
		${PYTHON_SITELIBDIR}/instant:../../devel/py-instant \
		${PYTHON_SITELIBDIR}/ufl:../../math/py-ufl \
		${PYTHON_SITELIBDIR}/viper:../../math/py-viper \
		${PYTHON_SITELIBDIR}/numpy:math/py-numpy \
		${PYTHON_SITELIBDIR}/ply:devel/py-ply \
		swig2.0:../../devel/swig20 \
		sphinx-build:textproc/py-sphinx

BUILD_DEPENDS=	${COMMON_DEPENDS}

# Require MPI
#		${LOCALBASE}/lib/libscotch.a:../../cad/scotch
#		${LOCALBASE}/lib/parmetis/libparmetis.a:math/parmetis

LIB_DEPENDS=	blas:math/blas \
		lapack:math/lapack \
		amd:math/suitesparse \
		umfpack:math/suitesparse \
		cholmod:math/suitesparse \
		boost_math_c99:devel/boost-libs \
		CGAL:math/cgal \
		xml2:textproc/libxml2 \
		cppunit:devel/cppunit \
		armadillo:../../math/armadillo \
		petsc:../../math/petsc33

# Dolfin requires MPI if Trilinos is enabled
#		amesos:../../math/trilinos
# Need better depend rule to ensure vtk5 is installed
RUN_DEPENDS=	${COMMON_DEPENDS}

USE_CMAKE=	yes
USE_PYTHON=	-2.7
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

MAN1=		dolfin-convert.1 \
		dolfin-order.1 \
		dolfin-plot.1 \
		dolfin-version.1
MANCOMPRESSED=	yes

MMVERSION=	1.2

post-patch:
	${REINPLACE_CMD} -e 's|os.path.join(os.path.sep,"usr")|os.path.normpath("${PREFIX}")|' ${WRKSRC}/site-packages/dolfin/compilemodules/compilemodule.py
	${REINPLACE_CMD} -e "s|/usr/local/lib/petsc|${LOCALBASE}|" ${WRKSRC}/cmake/modules/FindPETSc.cmake
	${REINPLACE_CMD} -e 's|$${PETSC_ARCH}/include|include|' ${WRKSRC}/cmake/modules/FindPETSc.cmake

.include <bsd.port.mk>
