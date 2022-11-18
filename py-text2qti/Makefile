PORTNAME=	text2qti
DISTVERSION=	0.6.0
CATEGORIES=	wip textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Create quizzes in QTI format from Markdown-based plain text
WWW=		https://pypi.python.org/project/text2qti/

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PKGNAMEPREFIX}BespON>0:wip/py-bespon@${PY_FLAVOR} \
		${PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
