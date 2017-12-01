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

USES=		gettext gmake pkgconfig
USE_GNOME=	gtk20 vte
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	Tetralet
GH_PROJECT=	LilyTerm

OPTIONS_DEFINE=	NLS
NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>
