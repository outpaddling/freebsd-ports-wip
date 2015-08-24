# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	pysam
PORTVERSION=	0.8.3
CATEGORIES=	biology
MASTER_SITES=	http://github.com/pysam-developers/pysam/archive/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Python module for reading and manipulating samfiles

LICENSE=	MIT

BUILD_DEPENDS=	cython:${PORTSDIR}/lang/cython

# Tested with python 2.5 and 2.6
# Still not finding ncurses
USES=		ncurses python:2
USE_PYTHON=	distutils
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
