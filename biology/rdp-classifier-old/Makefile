# Created by: Dan Siercks <dsiercks@uwm.edu>
# $FreeBSD$

PORTNAME=	classifier
PORTVERSION=	2.2
CATEGORIES=	biology
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	rdp-classifier/rdp-classifier/
PKGNAMEPREFIX=	rdp-
DISTNAME=	rdp_classifier_${PORTVERSION}

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	RDP Classifier is a naive Bayesian classfiier

LICENSE=	GPLv2

USES=		zip

PLIST_FILES=	etc/modulefiles/rdp-classifier/${PORTVERSION} \
		rdp-classifier/lib/commons-cli-1.2.jar \
		rdp-classifier/lib/junit_3.8.1.jar \
		rdp-classifier/rdp_classifier-${PORTVERSION}.jar

SUB_FILES=	modulefile
SUB_LIST+=	PORTVERSION=${PORTVERSION}

MODULE_PATH=	etc/modulefiles/${PKGNAMEPREFIX}${PORTNAME}

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/rdp_classifier-${PORTVERSION}.jar \
		${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} 'lib' \
		${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/${MODULE_PATH}
	${INSTALL_SCRIPT} ${WRKDIR}/modulefile \
		${STAGEDIR}${LOCALBASE}/${MODULE_PATH}/${PORTVERSION}

.include <bsd.port.mk>
