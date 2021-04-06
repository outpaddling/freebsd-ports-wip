
PORTNAME=	beast2
PORTVERSION=	2.4.3
DISTVERSIONPREFIX=	v
CATEGORIES=	wip biology java
MASTER_SITES=	http://github.com/CompEvol/beast2/releases/download/v2.4.3/
DISTNAME=	BEAST.v${PORTVERSION}.Linux

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bayesian phylogenetic analysis of molecular sequences

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		tar:tgz

USE_JAVA=	yes

# For source builds
#USE_GITHUB=	yes
#GH_ACCOUNT=	CompEvol

WRKSRC=		${WRKDIR}/beast
NO_BUILD=	yes
NO_ARCH=	yes

#LICENSE.txt          bin/                 lib/
#README.txt           examples/            templates/
#VERSION HISTORY.txt  images/

post-patch:
	${REINPLACE_CMD} -i '' -e 's|$$BEAST/lib|${JAVAJARDIR}|g' \
		${WRKSRC}/bin/*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${FILESDIR}/beast-init \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${JAVAJARDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} "images templates" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
