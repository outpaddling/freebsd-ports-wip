# Created by: Administrator <admin@FreeBSD-VM-1.meadows>
# $FreeBSD$

PORTNAME=	rdp-classifier
PORTVERSION=	2.10.1
CATEGORIES=	biology
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	rdp-classifier/rdp-classifier/
DISTNAME=	rdp_classifier_${PORTVERSION}
EXTRACT_SUFX=	.zip
MAINTAINER=	dsiercks@uwm.edu
COMMENT=	The RDP Classifier is a naive Bayesian classfiier that can rapidly and accurately provides taxonimic assignments from domain to genus, with confidence estimates for each assignment.
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/dist/classifier.jar ${STAGEDIR}${PREFIX}/${PORTNAME} 
	cd ${WRKSRC}/dist && ${COPYTREE_SHARE} 'lib' \
	${STAGEDIR}${PREFIX}/${PORTNAME}
.include <bsd.port.mk>
