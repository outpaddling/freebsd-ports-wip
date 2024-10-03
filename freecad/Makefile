PORTNAME=	FreeCAD
DISTVERSION=	0.21.2-5213
DISTVERSIONSUFFIX=	-gab44bd1f7b
PORTEPOCH=	1
CATEGORIES=	wip cad

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	General purpose 3D CAD modeller
WWW=		https://www.freecadweb.org/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	doxygen:devel/doxygen \
		pybind11-config:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside6-tools>0:devel/pyside6-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pivy>0:graphics/py-pivy@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/matplotlib/__init__.py:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_INCLUDEDIR}/CXX/Config.hxx:devel/py-cxx \
		swig:devel/swig \
		microsoft-gsl>0:devel/microsoft-gsl \
		googletest>0:devel/googletest
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libyaml-cpp.so:devel/yaml-cpp \
		libfreetype.so:print/freetype2 \
		libtbb.so:devel/onetbb \
		${PY_BOOST} \
		libpyside6.abi3.so:devel/pyside6@${PY_FLAVOR} \
		libshiboken6.abi3.so:devel/shiboken6 \
		libCoin.so:graphics/Coin \
		libfmt.so:devel/libfmt \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libvtksys-${VTK_VER}.so:math/vtk${VTK_VER:R} \
		libTKernel.so:cad/opencascade \
		libxerces-c.so:textproc/xerces-c3 \
		libboost_thread.so:devel/boost-libs \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreeimage.so:graphics/freeimage \
		libavutil.so:multimedia/ffmpeg4 \
		libmed.so:french/med \
		libshiboken2.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}.so:devel/shiboken2@${PY_FLAVOR} \
		libhdf5.so:science/hdf5 \
		libmpi.so:net/mpich

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pivy>0:graphics/py-pivy@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/matplotlib/__init__.py:math/py-matplotlib@${PY_FLAVOR}

USES=		dos2unix compiler:c++17-lang cmake cpe gl eigen:3 fortran gmake jpeg \
		localbase:ldflags mpi:openmpi pkgconfig python localbase qt:6 xorg \
		desktop-file-utils shared-mime-info shebangfix
USE_GITHUB=	yes
USE_XORG=	ice sm x11 xext xt
USE_GL=		gl glu
USE_QT=		base declarative location svg tools webchannel
# Qt5
# buildtools concurrent core designer gui linguisttools network opengl printsupport qmake:build widgets xml xmlpatterns
USE_LDCONFIG=	yes

CPE_VENDOR=	freecad_project

VTK_VER=	9.2

DOS2UNIX_GLOB=	*.txt *.h *.cpp *.py *.qss *.csv *.pov *.stp *.ui *.wrl *.WRL
SHEBANG_FILES=	src/Tools/freecad-thumbnailer

# our HDF5/CMake integration is messy, so workarounds are required below
CMAKE_ARGS+=	-DOCC_INCLUDE_DIR="${LOCALBASE}/include/OpenCASCADE" \
		-DOPENMPI_INCLUDE_DIRS="${LOCALBASE}/mpi/openmpi/include" \
		-DBUILD_QT5="OFF" \
		-DFREECAD_QT_VERSION="6" \
		-DPYTHON_LIBRARY="${PYTHONBASE}/lib/libpython${PYTHON_VER}${PYTHON_ABIVER}.so" \
		-DPYTHON_INCLUDE_DIR="${PYTHON_INCLUDEDIR}" \
		-DPYTHON_PACKAGES_PATH="${PYTHON_SITELIBDIR}" \
		-DPYTHON_EXECUTABLE="${PYTHON_CMD}" \
		-DPYCXX_INCLUDE_DIR="${PYTHON_INCLUDEDIR}" \
		-DBUILD_ASSEMBLY="OFF" \
		-DBUILD_DESIGNER_PLUGIN="ON" \
		-DBUILD_FLAT_MESH="ON" \
		-DBUILD_VR="OFF" \
		-DFREECAD_USE_EXTERNAL_FMT="ON" \
		-DFREECAD_CREATE_MAC_APP="OFF" \
		-DFREECAD_FREECAD_LIBPACK_USE="OFF" \
		-DFREECAD_USE_EXTERNAL_KDL="OFF" \
		-DFREECAD_USE_EXTERNAL_SMESH="OFF" \
		-DFREECAD_USE_FREETYPE="ON" \
		-DFREECAD_USE_PYBIND11="ON" \
		-Dpybind11_DIR="${PYTHON_SITELIBDIR}/pybind11/share/cmake/pybind11" \
		-DHDF5_CFLAGS="-I${LOCALBASE}/include" \
		-DHDF5_FOUND=TRUE \
		-DHDF5_VERSION="1.12.2" \
		-DHDF5_INCLUDE_DIRS="${LOCALBASE}/include/hdf5" \
		-DHDF5_LIBRARIES="-L${LOCALBASE}/lib -lhdf5" \
		-DHDF5_LIBRARY_DIRS="${LOCALBASE}/lib" \
		-DPYSIDE2RCCBINARY="${RCC}" \
		-DPYSIDE2UICBINARY="${UIC}" \
		-DBUILD_ENABLE_CXX_STD=C++17

# Remove before commit
WITH_DEBUG=		yes
CMAKE_INSTALL_PREFIX=	${PREFIX}/${PORTNAME}
# Install XDG icons and files to the standard path
CMAKE_ARGS+=	-DXDG_DATADIR="${PREFIX}/share"
# Debug issue #files/16116
# CFLAGS+=	-Wno-enum-constexpr-conversion

OPTIONS_DEFINE=	COLLADA

COLLADA_DESC=		Install pycollada for Collada files import
COLLADA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycollada>0:graphics/py-pycollada@${PY_FLAVOR}

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB=	WEBENGINE=""
USE_QT+=	webengine
.else
CMAKE_ARGS+=	-DBUILD_WEB:BOOL=OFF
PLIST_SUB=	WEBENGINE="@comment "
.endif

pre-configure:
	@${REINPLACE_CMD} -e '/self\.rev/s/Unknown/${DISTVERSION:C/.*-//}/' \
		${WRKSRC}/src/Tools/SubWCRev.py
# Install XDG icons and files to the standard path
	@${REINPLACE_CMD} -e 's/CMAKE_INSTALL_DATAROOTDIR/XDG_DATADIR/g' \
		${WRKSRC}/src/XDGData/CMakeLists.txt \
		${WRKSRC}/src/Gui/CMakeLists.txt

post-stage:
	${RM} -rf ${STAGEDIR}/usr/ports

post-install:
	${LN} -s ../${PORTNAME}/bin/FreeCAD ${STAGEDIR}${LOCALBASE}/bin/FreeCAD
	${LN} -s ../${PORTNAME}/bin/FreeCADCmd ${STAGEDIR}${LOCALBASE}/bin/FreeCADCmd
	${INSTALL_SCRIPT} ${WRKSRC}/src/Tools/freecad-thumbnailer \
		${STAGEDIR}${PREFIX}/bin/freecad-thumbnailer

.include <bsd.port.mk>
