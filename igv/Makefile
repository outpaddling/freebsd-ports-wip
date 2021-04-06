
PORTNAME=	igv
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.12
CATEGORIES=	wip biology java
MASTER_SITES=	http://software.broadinstitute.org/software/igv/sites/cancerinformatics.org.igv/files/images/:img
DISTFILES=	tools.png:img
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Visualization tool for genomic datasets

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	gradle>=6:devel/gradle

USES=		gettext-runtime
USE_GITHUB=	yes
GH_ACCOUNT=	igvteam
USE_JAVA=	11
NO_ARCH=	yes

MAKE_ENV+=	GRADLE_USER_HOME=${WRKDIR}

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	JAVA_HOME=${JAVA_HOME} \
		JAVAJARDIR=${JAVAJARDIR}

DESKTOP_ENTRIES="IGV" "Integrative Genomics Viewer" "${PREFIX}/share/pixmaps/igv.xpm" "${PORTNAME}" \
		"Biology;Science;" true

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} JAVA_VERSION=${JAVA_VERSION} gradle --no-daemon createDist

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}/igv
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	cd ${WRKSRC}/build/IGV-dist/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${JAVAJARDIR}/igv
	${INSTALL_DATA} ${WRKSRC}/build/IGV-dist/igv.args ${STAGEDIR}${JAVAJARDIR}/igv
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/tools.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
