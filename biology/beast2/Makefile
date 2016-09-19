# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	beast2
PORTVERSION=	2.4.3
CATEGORIES=	biology
MASTER_SITES=	https://github.com/CompEvol/beast2/releases/download/v2.4.3/
DISTNAME=	BEAST.v${PORTVERSION}.Linux
DISTVERSIONPREFIX=	v

MAINTAINER=	bacon4000@gmail.com
COMMENT=	

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		tar:tgz

USE_JAVA=	yes

#USE_GITHUB=	yes
#GH_ACCOUNT=	CompEvol

WRKSRC=		${WRKDIR}/beast
NO_BUILD=	yes

#LICENSE.txt          bin/                 lib/
#README.txt           examples/            templates/
#VERSION HISTORY.txt  images/              

post-patch:
	${REINPLACE_CMD} -e 's|$$BEAST/lib|${JAVAJARDIR}|g' \
		${WRKSRC}/bin/*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${JAVAJARDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} "images templates" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
