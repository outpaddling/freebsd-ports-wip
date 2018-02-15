# $FreeBSD$

PORTNAME=	dolfin
PORTVERSION=	2017.2.0
CATEGORIES=	wip
MASTER_SITES=	https://bitbucket.org/fenics-project/dolfin/downloads/

MAINTAINER=	bacon@manatee.acadix.biz
COMMENT=	Computational backend of FEniCS

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	eigen>0:math/eigen3 \
		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ffc>0:wip/py-ffc@${PY_FLAVOR} \
		swig30>0:devel/swig30
LIB_DEPENDS=	libboost_math_c99.so:devel/boost-libs \
		libhdf5.so:science/hdf5 \

# Optional
#		libamd.so:math/suitesparse \
		libblas.so:math/blas \
		liblapack.so:math/lapack \
		libumfpack.so:math/suitesparse \
		libcholmod.so:math/suitesparse \
		libCGAL.so:math/cgal \
		libxml2.so:textproc/libxml2 \
		libcppunit.so:devel/cppunit \
		libarmadillo.so:math/armadillo

USES=		cmake:outsource pkgconfig python:3.6+

CMAKE_ARGS+=	-DDOLFIN_ENABLE_MPI:BOOL=OFF \
		-DDOLFIN_AUTO_DETECT_MPI:BOOL=OFF \
		-DDOLFIN_ENABLE_DOCS:BOOL=OFF \
		-DDOLFIN_ENABLE_SLEPC:BOOL=OFF \
		-DDOLFIN_ENABLE_SLEPC4PY:BOOL=OFF \
		-DDOLFIN_ENABLE_TRILINOS:BOOL=OFF \
		-DDOLFIN_ENABLE_PARMETIS:BOOL=OFF \
		-DDOLFIN_ENABLE_SCOTCH:BOOL=OFF \
		-DDOLFIN_ENABLE_MTL4:BOOL=OFF \
		-DDOLFIN_ENABLE_PETSC:BOOL=OFF \
		-DDOLFIN_ENABLE_PETSC4PY:BOOL=OFF \
		-DDOLFIN_ENABLE_UMFPACK:BOOL=OFF \
		-DDOLFIN_ENABLE_CHOLMOD:BOOL=OFF \
		-DDOLFIN_ENABLE_SPHINX:BOOL=OFF \
		-DDOLFIN_MAN_DIR:PATH=man \

# Optional \
		-DPETSC_DIR:PATH=${LOCALBASE} \
		-DCHOLMOD_DIR:PATH=${LOCALBASE} \
		-DUMFPACK_DIR:PATH=${LOCALBASE} \
		-DDOLFIN_PKGCONFIG_DIR:PATH=${LOCALBASE}/libdata/pkgconfig

# Doxygen chokes, resulting in missing .i files, so disable it
# Should dolfin build even be trying this with DOLFIN_ENABLE_DOCS=OFF?
post-patch:
	${REINPLACE_CMD} -e "s|'doxygen'|'hide-doxygen'|g' \
		cmake/scripts/generate-swig-docstrings.p

post-configure:
	${REINPLACE_CMD} -e 's| dolfin/swig/[a-z]*/pre\.i| ${WRKSRC}/&|g' \
		${WRKDIR}/.build/build.ninja
	${REINPLACE_CMD} -e 's| dolfin/swig/[a-z]*/post\.i| ${WRKSRC}/&|g' \
		${WRKDIR}/.build/build.ninja
	${REINPLACE_CMD} -e 's|${WRKSRC}/ |${WRKSRC}/|g' \
		${WRKDIR}/.build/build.ninja

.include <bsd.port.mk>
