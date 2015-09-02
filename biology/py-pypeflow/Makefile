# Created by: Jacob Sonnenberg <jacobsonnenberg0@gmail.com>
# $FreeBSD$

PORTNAME=	pypeflow
# Must use the same version of dazz_db, daligner, pypeflow, and falcon!
PORTVERSION=	2015.08.17
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jacobsonnenberg0@gmail.com
COMMENT=	Lightweight and reusable make/flow data process library

LICENSE=	MIT

USES=		python tar:xz
USE_PYTHON=	distutils

WRKSRC=		${WRKDIR}/${DISTNAME}

do-install:
	echo ${PYDISTUTILS_INSTALLARGS}

.include <bsd.port.mk>
