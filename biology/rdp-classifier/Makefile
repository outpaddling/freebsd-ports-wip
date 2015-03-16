# Created by: Dan Siercks <dsiercks@uwm.edu>
# $FreeBSD$

PORTNAME=	classifier
PORTVERSION=	2.10.1
CATEGORIES=	biology
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	rdp-classifier/rdp-classifier/
PKGNAMEPREFIX=	rdp-
DISTNAME=	rdp_classifier_${PORTVERSION}

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	RDP Classifier is a naive Bayesian classfiier

LICENSE=	GPLv2

USES=		zip

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/dist/classifier.jar \
		${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}
	cd ${WRKSRC}/dist && ${COPYTREE_SHARE} 'lib' \
		${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}
.include <bsd.port.mk>
