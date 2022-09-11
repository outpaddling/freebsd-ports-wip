PORTNAME=	qbmon
DISTVERSION=	g20200628
CATEGORIES=	wip

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Simple, QT-based, desktop-independent battery monitor
WWW=		https://github.com/outpaddling/qbmon

LICENSE=	BSD2CLAUSE

USES=		gl qt:5 qmake
USE_QT=		core widgets gui
USE_GL=		gl
USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_TAGNAME=	d9798f38

PLIST_FILES=	bin/qbmon etc/xdg/autostart/qbmon.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qbmon ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/autostart
	${INSTALL_DATA} ${FILESDIR}/qbmon.desktop \
		${STAGEDIR}${PREFIX}/etc/xdg/autostart

.include <bsd.port.mk>
