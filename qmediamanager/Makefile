PORTNAME=	qmediamanager
DISTVERSION=	0.0.0.3
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	GUI tool for managing removable media
WWW=		https://github.com/outpaddling/qmediamanager

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	npmount>0:wip/npmount

USES=		gl qmake qt:5
USE_QT=		buildtools:build core gui qmake:build widgets
USE_GL=		gl
USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_TAGNAME=	e40c589eb541427e46fbb9da957e7028e32d3b78

PLIST_FILES=	bin/QMediaManager

do-install:
	${INSTALL} -c ${WRKSRC}/QMediaManager ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
