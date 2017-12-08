# Created by: Jason Bacon <bacon@manatee.acadix.biz>
# $FreeBSD$

PORTNAME=	lilyterm
PORTVERSION=	0.9.9.4
DISTVERSIONPREFIX=	v
CATEGORIES=	wip editors

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lightweight, but functional terminal emulator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext gmake pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk20 vte
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	Tetralet
GH_PROJECT=	LilyTerm

USE_XORG=	x11 xext

OPTIONS_DEFINE=	NLS
NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

WRKSRC=		${WRKDIR}/LilyTerm-${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lilyterm

.include <bsd.port.mk>
