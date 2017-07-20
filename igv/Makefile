# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	igv
PORTVERSION=	2.3.97
CATEGORIES=	wip biology java
MASTER_SITES=	http://data.broadinstitute.org/igv/projects/downloads/
DISTNAME=	IGV_${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Visualization tool for interactive exploration of genomic datasets

LICENSE=	MIT

USES=		zip
USE_JAVA=	yes

NO_BUILD=	yes

SUB_FILES=	igv.sh

PLIST_FILES=	bin/igv %%JAVAJARDIR%%/igv.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/igv.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/igv.sh ${STAGEDIR}${PREFIX}/bin/igv

.include <bsd.port.mk>
