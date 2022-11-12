PORTNAME=	brain-mesh-builder
DISTVERSIONPREFIX=	v.
DISTVERSION=	1.0
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Surface mesh building based on 3-dimensional image stacks
WWW=		https://github.com/hwm2746/brain-mesh-builder/releases

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libGraphicsMagick++.so:graphics/GraphicsMagick \
		libjbig.so:graphics/jbigkit \
		libwebp.so:graphics/webp \
		libwebpmux.so:graphics/webp \
		liblcms2.so:graphics/lcms2 \
		libtiff.so:graphics/tiff \
		libfreetype.so:print/freetype2 \
		libjasper.so:graphics/jasper \
		libjxl.so:graphics/libjxl \
		libjxl_threads.so:graphics/libjxl \
		libpng16.so:graphics/png \
		libwmflite.so:graphics/libwmf

USES=		gmake gnome jpeg xorg
USE_XORG=	ice sm x11 xext
USE_GNOME=	libxml2
USE_GITHUB=	yes

GH_ACCOUNT=	hwm2746

CXXFLAGS+=	-Wall

PLIST_FILES=	bin/dodri

post-extract:
	${RM} ${WRKSRC}/bin/* ${WRKSRC}/obj/*.o ${WRKSRC}/obj/io/*.o

.include <bsd.port.mk>
