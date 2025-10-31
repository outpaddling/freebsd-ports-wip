PORTNAME=		amide
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.6-20
DISTVERSIONSUFFIX=	-gc02babd
CATEGORIES=		wip science

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	AMIDE's a Medical Image Data Examiner
WWW=		https://example.com/amide

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	medcon:graphics/xmedcon \
		gtkdocize:textproc/gtk-doc \
		volpack>0:graphics/volpack
LIB_DEPENDS=	libgsl.so:math/gsl \
		libmdc.so:graphics/xmedcon \
		libpng16.so:graphics/png \
		libavcodec.so:multimedia/ffmpeg \
		libtiff.so:graphics/tiff \
		libdcmimage.so:graphics/dcmtk \
		libopenjp2.so:graphics/openjpeg

USES=		autoreconf:2.69 desktop-file-utils gmake gnome libtool localbase
NLS_USES=	gettext
USE_GITHUB=	yes
USE_GNOME=	gconf2 libgnomecanvas gtk20 intltool
GH_ACCOUNT=	ferdymercury

MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=		yes
# Requires gnome-vfs2.  Not in ports??
CONFIGURE_ARGS=		--enable-gnome-vfs=no
WITH_DEBUG=		yes	# Until abort on startup is fixed

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_SUB=		yes

pre-configure:
	(cd ${WRKSRC} && intltoolize)
	(cd ${WRKSRC} && libtoolize)
	(cd ${WRKSRC} && gtkdocize)
	(cd ${WRKSRC} && ${TOUCH} gnome-doc-utils.make)

.include <bsd.port.mk>
