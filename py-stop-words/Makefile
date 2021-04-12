PORTNAME=	stop-words
PORTVERSION=	2015.2.23.1
CATEGORIES=	wip python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Get list of common stop words in various languages in Python

LICENSE=	BSD3CLAUSE
#LICENSE_FILE=

PATCH_DEPENDS=	stop-words>=0:wip/stop-words

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	Alir3z4
GH_PROJECT=	python-${PORTNAME}

post-patch:
	${CP} ${LOCALBASE}/share/stop-words/* ${WRKSRC}/stop_words/stop-words

.include <bsd.port.mk>
