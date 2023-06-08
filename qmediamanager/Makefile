PORTNAME=	qmediamanager
DISTVERSION=	0.0.0.16
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	GUI tool for managing removable media
WWW=		https://github.com/outpaddling/qmediamanager

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libxtend>=0.1.7.21:wip/libxtend
LIB_DEPENDS=	libxtend.so:wip/libxtend
RUN_DEPENDS=	npmount>0:wip/npmount \
		automount>0:sysutils/automount \
		auto-admin>=0.7.15.23:wip/auto-admin \
		rxvt-unicode>0:x11/rxvt-unicode

USES=		gl qmake qt:6
USE_QT=		base tools:build
USE_GL=		gl
USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_TAGNAME=	def8d5bf2875b527f8cd8c44744661196b25fc7c

WITH_DEBUG=	yes

PLIST_FILES=	bin/qmediamanager man/man1/qmediamanager.1.gz

do-install:
	${INSTALL} -c ${WRKSRC}/qmediamanager ${STAGEDIR}${PREFIX}/bin
	${INSTALL} -c ${WRKSRC}/Man/qmediamanager.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
