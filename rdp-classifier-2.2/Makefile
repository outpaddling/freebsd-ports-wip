PORTNAME=	classifier
PORTVERSION=	2.2
CATEGORIES=	wip biology java
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	rdp-classifier/rdp-classifier/
PKGNAMEPREFIX=	rdp-
PKGNAMESUFFIX=	22
DISTNAME=	rdp_classifier_${PORTVERSION}

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	RDP Classifier is a naive Bayesian classfiier

LICENSE=	GPLv2

USES=		zip
USE_JAVA=	yes

# SUB_FILES=	modulefile
# SUB_LIST+=	PORTVERSION=${PORTVERSION}

# MODULE_PATH=	etc/modulefiles/${PKGNAMEPREFIX}${PORTNAME}

NO_BUILD=	yes

RDP_PREFIX=	${JAVAJARDIR}/${PKGNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${RDP_PREFIX}
	${INSTALL_SCRIPT} ${WRKSRC}/rdp_classifier-${PORTVERSION}.jar \
		${STAGEDIR}${RDP_PREFIX}
	cd ${WRKSRC} && ${COPYTREE_SHARE} 'lib' \
		${STAGEDIR}${RDP_PREFIX}
	# @${MKDIR} ${STAGEDIR}${PREFIX}/${MODULE_PATH}
	# ${INSTALL_SCRIPT} ${WRKDIR}/modulefile \
		# ${STAGEDIR}${LOCALBASE}/${MODULE_PATH}/${PORTVERSION}

.include <bsd.port.mk>
