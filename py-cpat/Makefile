PORTNAME=	cpat
PORTVERSION=	1.2.2
CATEGORIES=	wip biology
MASTER_SITES=	http://pypi.python.org/packages/source/d/distribute/ \
		SF/rna-cpat/v${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	CPAT-${PORTVERSION}
DISTFILES=	CPAT-${PORTVERSION}.tar.gz distribute-0.6.10.tar.gz
EXTRACT_ONLY=	CPAT-${PORTVERSION}.tar.gz

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Overcomes alignment search limitations using logistic regression model
WWW=		https://rna-cpat.sourceforge.net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/doc/COPYING

#BUILD_DEPENDS=	${PKGNAMEPREFIX}pysam>=0:wip/py-pysam
#RUN_DEPENDS=	${PKGNAMEPREFIX}pysam>=0:wip/py-pysam
# numpy, cython, R

USES=		python:3.6+
USE_PYTHON=	distutils

post-extract:
	${CP} ${DISTDIR}/distribute-0.6.10.tar.gz ${WRKSRC}

.include <bsd.port.mk>
