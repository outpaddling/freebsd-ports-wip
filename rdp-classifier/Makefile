
PORTNAME=	classifier
PORTVERSION=	2.12
CATEGORIES=	wip biology java
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	rdp-classifier/rdp-classifier/
PKGNAMEPREFIX=	rdp-
DISTNAME=	rdp_classifier_${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	RDP Classifier is a naive Bayesian classfiier

LICENSE=	GPLv2

USES=		zip
USE_JAVA=	yes

# The modulefile is useless.  Does some calling app expect to find
# rdp-classifier in PATH?
# SUB_FILES=	modulefile
# SUB_LIST+=	PORTVERSION=${PORTVERSION} RDP_PREFIX=${RDP_PREFIX}
# MODULE_PATH=	${PREFIX}/etc/modulefiles/${PKGNAMEPREFIX}${PORTNAME}

RDP_PREFIX=	${JAVAJARDIR}

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${RDP_PREFIX}
	${INSTALL_SCRIPT} ${WRKSRC}/dist/classifier.jar \
		${STAGEDIR}${RDP_PREFIX}
	cd ${WRKSRC}/dist && ${COPYTREE_SHARE} 'lib' \
		${STAGEDIR}${RDP_PREFIX}
	# @${MKDIR} ${STAGEDIR}${MODULE_PATH}
	# ${INSTALL_SCRIPT} ${WRKDIR}/modulefile \
	#	${STAGEDIR}${MODULE_PATH}/${PORTVERSION}

.include <bsd.port.mk>
