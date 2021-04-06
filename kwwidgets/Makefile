
PORTNAME=	kwwidgets
PORTVERSION=	2012.05.06
CATEGORIES=	wip science
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=

CONFLICTS=	vtk-4.*

USE_PYTHON=	yes
USE_CMAKE=	yes
USE_TCL=	84+
USE_TK=		84+
USE_LDCONFIG=	${PREFIX}/lib/KWWidgets

CFLAGS+=	-fPIC -I${PYTHON_INCLUDEDIR}

LIB_DEPENDS=	vtkCommon.5:math/vtk5

CMAKE_ARGS+=	-DTCL_INCLUDE_PATH=${LOCALBASE}/include/tcl${TCL_VER} \
		-DTK_INCLUDE_PATH=${LOCALBASE}/include/tk${TK_VER}

# CONFIGURE_ENV+=	PYTHON_INCLUDEDIR=${PYTHON_INCLUDEDIR}

post-patch:
	${REINPLACE_CMD} -e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|g' ${WRKSRC}/vtkKWResourceUtilities.cxx

post-install:
	${LN} ${PREFIX}/lib/KWWidgets/libKWWidgets.so \
	      ${PREFIX}/lib/KWWidgets/libKWWidgets.so.1

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
