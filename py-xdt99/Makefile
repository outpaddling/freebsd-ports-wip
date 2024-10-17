PORTNAME=	xdt99
DISTVERSION=	3.6.5
CATEGORIES=	wip emulators python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	TMS 99xx Cross-Development Tools
WWW=		https://github.com/endlos99/xdt99

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	endlos99
SHEBANG_FILES=	${WRKSRC}/*.py

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/[a-z]*.py ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
