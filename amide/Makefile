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

BUILD_DEPENDS=	medcon:graphics/xmedcon
USES=		autoreconf libtool
USE_GITHUB=	yes
USE_GNOME=	gtk20 intltool

GH_ACCOUNT=	ferdymercury

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doc

.include <bsd.port.mk>
