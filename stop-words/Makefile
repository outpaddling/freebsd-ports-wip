PORTNAME=	stop-words
PORTVERSION=	2015.02.21
CATEGORIES=	wip

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	List of common stop words in various languages
WWW=		https://github.com/Alir3z4/stop-words

LICENSE=	CC-BY-4.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	Alir3z4

NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
