# $FreeBSD$

PORTNAME=	igv
DISTVERSION=	2.8.13
CATEGORIES=	wip biology java
MASTER_SITES=	https://data.broadinstitute.org/igv/projects/downloads/2.8/
DISTNAME=	IGV_${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Visualization tool for genomic datasets

LICENSE=	MIT

USES=		zip
USE_JAVA=	11

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	JAVA_HOME=${JAVA_HOME} \
		JAVAJARDIR=${JAVAJARDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}/igv ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${STAGEDIR}${JAVAJARDIR}/igv
	${INSTALL_DATA} ${WRKSRC}/igv.args ${STAGEDIR}${JAVAJARDIR}/igv
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} genomes ${STAGEDIR}${JAVAJARDIR}/igv)
	${INSTALL_DATA} ${WRKSRC}/IGV_64.png ${STAGEDIR}${PREFIX}/share/pixmaps/igv.png

.include <bsd.port.mk>
