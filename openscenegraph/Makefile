PORTNAME=	openscenegraph
DISTVERSIONPREFIX=	OpenSceneGraph-
DISTVERSION=	3.6.5
CATEGORIES=	wip cad

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Open source high performance 3D graphics toolkit
WWW=		http://www.openscenegraph.com

# Fake: OpenSceneGraph license
LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libcurl.so:ftp/curl \
		libavformat.so:multimedia/ffmpeg \
		libavdevice.so:multimedia/ffmpeg \
		libavcodec.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg \
		libswresample.so:multimedia/ffmpeg \
		libavresample.so:multimedia/ffmpeg \
		libfreetype.so:print/freetype2 \
		libgdal.so:graphics/gdal \
		libgif.so:graphics/giflib \
		libjasper.so:graphics/jasper \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff \
		libpoppler-glib.so:graphics/poppler-glib \
		libvncclient.so:net/libvncserver


USES=		cmake:noninja gettext-runtime gl gnome gstreamer jpeg \
		localbase:ldflags sdl xorg
USE_GL=		gl
USE_GNOME=	cairo gdkpixbuf2 glib20 librsvg2
USE_LDCONFIG=	yes
USE_SDL=	sdl
USE_XORG=	x11 xinerama xrandr

USE_GITHUB=	yes
GH_PROJECT=	OpenSceneGraph

.include <bsd.port.mk>
