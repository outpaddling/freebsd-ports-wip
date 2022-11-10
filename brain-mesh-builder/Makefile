PORTNAME=	brain-mesh-builder
DISTVERSIONPREFIX=	v.
DISTVERSION=	1.0
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Surface mesh building based on 3-dimensional image stacks
WWW=		https://github.com/hwm2746/brain-mesh-builder/releases

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libGraphicsMagick++.so:graphics/GraphicsMagick
LIB_DEPENDS+=	libjbig.so:graphics/jbigkit
LIB_DEPENDS+=	libwebp.so:graphics/webp
LIB_DEPENDS+=	libwebpmux.so:graphics/webp
LIB_DEPENDS+=	liblcms2.so:graphics/lcms2
LIB_DEPENDS+=	libtiff.so:graphics/tiff
LIB_DEPENDS+=	libfreetype.so:print/freetype2
LIB_DEPENDS+=	libjasper.so:graphics/jasper
LIB_DEPENDS+=	libjxl.so:graphics/libjxl
LIB_DEPENDS+=	libjxl_threads.so:graphics/libjxl
LIB_DEPENDS+=	libpng16.so:graphics/png
LIB_DEPENDS+=	libwmflite.so:graphics/libwmf

USES=		gmake gnome jpeg xorg
USE_XORG=	ice sm x11 xext
USE_GNOME=	libxml2
USE_GITHUB=	yes

GH_ACCOUNT=	hwm2746

# CXXFLAGS+=	-std=gnu++14
# MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/dodri

post-extract:
	${RM} ${WRKSRC}/bin/* ${WRKSRC}/obj/*.o ${WRKSRC}/obj/io/*.o

.include <bsd.port.mk>
