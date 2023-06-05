PORTNAME=	qmediamanager
DISTVERSION=	0.0.0.8
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	GUI tool for managing removable media
WWW=		https://github.com/outpaddling/qmediamanager

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	npmount>0:wip/npmount automount>0:sysutils/automount

USES=		gl qmake qt:5
USE_QT=		buildtools:build core gui qmake:build widgets
USE_GL=		gl
USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_TAGNAME=	c10d444abd7983e0bf05a4abc516f0131a851be1

PLIST_FILES=	bin/qmediamanager man/man1/qmediamanager.1.gz

do-install:
	${INSTALL} -c ${WRKSRC}/qmediamanager ${STAGEDIR}${PREFIX}/bin
	${INSTALL} -c ${WRKSRC}/Man/qmediamanager.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
