# Created by: Jason Bacon <jwb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	htseq
PORTVERSION=	0.6.1p1
CATEGORIES=	wip biology python
MASTER_SITES=		${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=	source/H/HTSeq
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	HTSeq-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Framework to analyze data from high-throughput sequencing assays

LICENSE=	GPLv3

BUILD_DEPENDS=	${PKGNAMEPREFIX}numpy>=1.9.2:math/py-numpy \
		${PKGNAMEPREFIX}matplotlib>=1.4.3:math/py-matplotlib

USES=		python
USE_PYTHON=	distutils

.include <bsd.port.mk>
