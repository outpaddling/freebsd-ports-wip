# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	cpat
PORTVERSION=	1.2.2
CATEGORIES=	biology
MASTER_SITES=	http://pypi.python.org/packages/source/d/distribute/ \
		SF/rna-cpat/v${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	CPAT-${PORTVERSION}
DISTFILES=	CPAT-${PORTVERSION}.tar.gz distribute-0.6.10.tar.gz
EXTRACT_ONLY=	CPAT-${PORTVERSION}.tar.gz

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Overcomes alignment search limitations using logistic regression model

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/doc/COPYING

#BUILD_DEPENDS=	${PKGNAMEPREFIX}pysam>=0:/usr/wip/biology/py-pysam
#RUN_DEPENDS=	${PKGNAMEPREFIX}pysam>=0:/usr/wip/biology/py-pysam
# numpy, cython, R

USES=		python
USE_PYTHON=	distutils

post-extract:
	${CP} ${DISTDIR}/distribute-0.6.10.tar.gz ${WRKSRC}

.include <bsd.port.mk>
