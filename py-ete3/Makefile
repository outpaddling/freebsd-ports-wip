
PORTNAME=	ete3
PORTVERSION=	3.1.1
CATEGORIES=	wip biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Python Environment for (phylogenetic) Tree Exploration

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+ shebangfix
SHEBANG_FILES=	ete3/tools/ete.py ete3/tools/ete_build.py
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
