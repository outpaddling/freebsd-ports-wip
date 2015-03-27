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

PLIST_FILES=	etc/modulefiles/classifier/2.2 \
		rdp-classifier/lib/commons-cli-1.2.jar \
		rdp-classifier/lib/junit_3.8.1.jar \
		rdp-classifier/rdp_classifier-2.2.jar

SUB_FILES=	modulefile

MODULE_PATH=	etc/modulefiles/${PKGNAMEPREFIX}${PORTNAME}

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/rdp_classifier-2.2.jar \
		${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} 'lib' \
		${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/${MODULE_PATH}
	${INSTALL_SCRIPT} ${FILESDIR}/modulefile \
		${STAGEDIR}${LOCALBASE}/${MODULE_PATH}/${PORTVERSION}

.include <bsd.port.mk>
