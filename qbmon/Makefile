# $FreeBSD$

PORTNAME=	qbmon
DISTVERSION=	g20200628
CATEGORIES=	wip

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Simple, QT-based, desktop-independent battery monitor

LICENSE=	BSD2CLAUSE

USES=		gl qt:5 qmake
USE_QT=		core widgets gui
USE_GL=		gl
USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_TAGNAME=	d9798f38

PLIST_FILES=	bin/qbmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qbmon ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
