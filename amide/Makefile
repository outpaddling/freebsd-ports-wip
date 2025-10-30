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
		autoconf2.69:devel/autoconf2.69 \
		gtkdocize:textproc/gtk-doc
LIB_DEPENDS=	libgsl.so:math/gsl \
		libmdc.so:graphics/xmedcon \
		libpng16.so:graphics/png \
		libavcodec.so:multimedia/ffmpeg \
		libtiff.so:graphics/tiff \
		libdcmimage.so:graphics/dcmtk \
		libopenjp2.so:graphics/openjpeg
USES=		desktop-file-utils gettext gmake gnome libtool
USE_GITHUB=	yes
USE_GNOME=	gconf2 libgnomecanvas gtk20 intltool

GH_ACCOUNT=	ferdymercury

MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=	yes
# Requires gnome-vfs2.  Not in ports??
CONFIGURE_ARGS=	--enable-gnome-vfs=no

pre-configure:
	# (cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf2.69)
	(cd ${WRKSRC} && intltoolize)
	(cd ${WRKSRC} && libtoolize)
	(cd ${WRKSRC} && gtkdocize)
	(cd ${WRKSRC} && ${TOUCH} gnome-doc-utils.make)
	(cd ${WRKSRC} && autoreconf2.69 --install)

.include <bsd.port.mk>
