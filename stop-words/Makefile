
PORTNAME=	stop-words
PORTVERSION=	2015.02.21
CATEGORIES=	wip

MAINTAINER=	bacon@imacbsd.acadix.biz
COMMENT=	List of common stop words in various languages

LICENSE=	CC-BY-4.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	Alir3z4

NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
