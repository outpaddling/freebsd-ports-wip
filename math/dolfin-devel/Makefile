# Created by:	Jason Bacon
# $FreeBSD$

PORTNAME=	dolfin
PORTVERSION=	${MMVERSION}.0
CATEGORIES=	math python
MASTER_SITES=	http://launchpad.net/dolfin/${MMVERSION}.x/${MMVERSION}.0/+download/

MAINTAINER=	jwbacon@tds.net
COMMENT=	C++/Python interface of FEniCS

LICENSE=	LGPL3

# Note: Currently can't tell if parmetis was built with openmpi or mpich2
# Leave paths as ../../ instead of ${PORTSDIR} until committed for
# development purposes
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/ufc_utils:../../math/ufc \
		${PYTHON_SITELIBDIR}/ffc:../../math/py-ffc \
		${PYTHON_SITELIBDIR}/FIAT:../../math/py-fiat \
		${PYTHON_SITELIBDIR}/instant:../../devel/py-instant \
		${PYTHON_SITELIBDIR}/ufl:../../math/py-ufl \
		${PYTHON_SITELIBDIR}/viper:../../math/py-viper \
		${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy \
		${PYTHON_SITELIBDIR}/ply:${PORTSDIR}/devel/py-ply \
		swig2.0:../../devel/swig20 \
		${LOCALBASE}/petsc/lib/libpetsc.a:../../math/petsc31 \
		sphinx-build:${PORTSDIR}/textproc/py-sphinx

# Require MPI
#		${LOCALBASE}/lib/libscotch.a:../../cad/scotch
#		${LOCALBASE}/lib/parmetis/libparmetis.a:${PORTSDIR}/math/parmetis

LIB_DEPENDS=	blas:${PORTSDIR}/math/blas \
		lapack:${PORTSDIR}/math/lapack \
		amd:${PORTSDIR}/math/suitesparse \
		umfpack:${PORTSDIR}/math/suitesparse \
		cholmod:${PORTSDIR}/math/suitesparse \
		boost_math_c99:${PORTSDIR}/devel/boost-libs \
		CGAL:${PORTSDIR}/math/cgal \
		xml2:${PORTSDIR}/textproc/libxml2 \
		cppunit:${PORTSDIR}/devel/cppunit \
		armadillo:../../math/armadillo

# Dolfin requires MPI if Trilinos is enabled
#		amesos:../../math/trilinos
# Need better depend rule to ensure vtk5 is installed
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/ufc_utils:../../math/ufc \
		${PYTHON_SITELIBDIR}/ffc:../../math/py-ffc \
		${PYTHON_SITELIBDIR}/FIAT:../../math/py-fiat \
		${PYTHON_SITELIBDIR}/instant:../../devel/py-instant \
		${PYTHON_SITELIBDIR}/ufl:../../math/py-ufl \
		${PYTHON_SITELIBDIR}/viper:../../math/py-viper \
		${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy \
		${PYTHON_SITELIBDIR}/ply:${PORTSDIR}/devel/py-ply \
		sphinx-build:${PORTSDIR}/textproc/py-sphinx \
		vtkpython:${PORTSDIR}/math/vtk5

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
		-DCHOLMOD_DIR:PATH=${LOCALBASE} \
		-DUMFPACK_DIR:PATH=${LOCALBASE} \
		-DPETSC_ARCH=${OPSYS:L} \
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
	${REINPLACE_CMD} -e 's|/usr/local/lib/petsc|/usr/local/petsc|' ${WRKSRC}/cmake/modules/FindPETSc.cmake
	${REINPLACE_CMD} -e 's|$${PETSC_ARCH}/include|include|' ${WRKSRC}/cmake/modules/FindPETSc.cmake

.include <bsd.port.mk>
