PORTNAME=	dolfin
DISTVERSION=	2017.2.0
CATEGORIES=	wip
MASTER_SITES=	https://bitbucket.org/fenics-project/dolfin/downloads/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Computational backend of FEniCS
WWW=		https://fenicsproject.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	eigen>0:math/eigen3 \
		swig30>0:devel/swig30 \
		${COMMON_DEPENDS}
LIB_DEPENDS=	libboost_math_c99.so:devel/boost-libs \
		libhdf5.so:science/hdf5 \
		libopenblas.so:math/openblas \
		liblapack.so:math/lapack \
		libCGAL.so:math/cgal \
		libamd.so:math/suitesparse \
		libumfpack.so:math/suitesparse \
		libcholmod.so:math/suitesparse \
		libsz.so:science/szip
RUN_DEPENDS=	${COMMON_DEPENDS}

# Optional \
		libxml2.so:textproc/libxml2 \
		libcppunit.so:devel/cppunit \
		libarmadillo.so:math/armadillo

USES=		cmake:noninja pkgconfig python:3.6+ shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	test/unit/python/scripts/run.sh \
		test/unit/python/scripts/splitmpidebug.sh \
		test/unit/python/scripts/clean.sh \
		test/unit/python/scripts/prun.sh \
		test/unit/python/scripts/mpidebug.sh \
		test/unit/python/scripts/mpirun.sh \
		site-packages/dolfin_utils/pjobs/sge.py \
		site-packages/dolfin_utils/pjobs/slurm.py \
		site-packages/dolfin_utils/pjobs/torque.py \
		utils/scripts/pdebug \
		cmake/templates/fenics-version.in \
		cmake/templates/dolfin-get-demos.in \
		cmake/templates/dolfin-version.in \
		scripts/dolfin-convert/dolfin-convert \
		scripts/dolfin-order/dolfin-order \
		scripts/dolfin-plot/dolfin-plot

CMAKE_ARGS+=	-DDOLFIN_ENABLE_MPI:BOOL=OFF \
		-DDOLFIN_AUTO_DETECT_MPI:BOOL=OFF \
		-DDOLFIN_ENABLE_DOCS:BOOL=OFF \
		-DDOLFIN_ENABLE_SLEPC:BOOL=OFF \
		-DDOLFIN_ENABLE_SLEPC4PY:BOOL=OFF \
		-DDOLFIN_ENABLE_TRILINOS:BOOL=OFF \
		-DDOLFIN_ENABLE_PARMETIS:BOOL=OFF \
		-DDOLFIN_ENABLE_SCOTCH:BOOL=OFF \
		-DDOLFIN_ENABLE_PETSC:BOOL=OFF \
		-DDOLFIN_ENABLE_PETSC4PY:BOOL=OFF \
		-DDOLFIN_ENABLE_UMFPACK:BOOL=ON \
		-DDOLFIN_ENABLE_CHOLMOD:BOOL=ON \
		-DDOLFIN_ENABLE_SPHINX:BOOL=OFF \
		-DDOLFIN_MAN_DIR:PATH=man \
		-DCHOLMOD_DIR:PATH=${LOCALBASE} \
		-DUMFPACK_DIR:PATH=${LOCALBASE} \
		-DBLAS_Accelerate_LIBRARY:PATH=${LOCALBASE}/lib/libopenblas.a

DV=		${DISTVERSION}
COMMON_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ffc==${DV}:wip/py-ffc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}

# Doxygen chokes, resulting in missing .i files, so disable it
# Should dolfin build even be trying this with DOLFIN_ENABLE_DOCS=OFF?
post-patch:
	${REINPLACE_CMD} -e "s|'doxygen'|'hide-doxygen'|g" \
		${WRKSRC}/cmake/scripts/generate-swig-docstrings.py

.include <bsd.port.mk>
