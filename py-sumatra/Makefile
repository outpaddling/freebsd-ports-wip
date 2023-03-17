PORTNAME=	sumatra
PORTVERSION=	0.7.4
CATEGORIES=	wip science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Sumatra-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	A tool for automated tracking of computation-based scientific projects
WWW=		https://pypi.python.org/pypi/Sumatra

LICENSE=	BSD2CLAUSE
#LICENSE_FILE=	

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pathlib>0:devel/py-pathlib \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future \
		${PYTHON_PKGNAMEPREFIX}parameters>0:wip/py-parameters \
		${PYTHON_PKGNAMEPREFIX}django18>0:www/py-django18 \
		${PYTHON_PKGNAMEPREFIX}django-tagging>0:www/py-django-tagging \
		${PYTHON_PKGNAMEPREFIX}httplib2>0:www/py-httplib2 \

USES=		python:3.6+
USE_PYTHON=	distutils

.include <bsd.port.mk>
