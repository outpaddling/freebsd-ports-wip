PORTNAME=	igv
DISTVERSION=	2.16.0
CATEGORIES=	wip biology java
MASTER_SITES=	https://data.broadinstitute.org/igv/projects/downloads/${DISTVERSION:R}/
DISTNAME=	IGV_${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Visualization tool for genomic datasets
WWW=		https://software.broadinstitute.org/software/igv/

LICENSE=	MIT

USES=		desktop-file-utils zip
USE_JAVA=	11

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	JAVA_HOME=${JAVA_HOME} \
		JAVAJARDIR=${JAVAJARDIR}

DESKTOP_ENTRIES="IGV" "Integrative Genomics Viewer" \
		"${PREFIX}/share/pixmaps/igv.xpm" \
		"${PORTNAME}" "Biology;Science;" true

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}/igv ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${STAGEDIR}${JAVAJARDIR}/igv
	${INSTALL_DATA} ${WRKSRC}/igv.args ${STAGEDIR}${JAVAJARDIR}/igv
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} genomes ${STAGEDIR}${JAVAJARDIR}/igv)

.include <bsd.port.mk>
