# Created by: Dan Siercks <dsiercks@uwm.edu>
# $FreeBSD$

PORTNAME=	classifier
PORTVERSION=	2.2
CATEGORIES=	biology
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	rdp-classifier/rdp-classifier/
PKGNAMEPREFIX=	rdp-
PKGNAMESUFFIX=	22
DISTNAME=	rdp_classifier_${PORTVERSION}

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	RDP Classifier is a naive Bayesian classfiier

LICENSE=	GPLv2

USES=		zip
# Version?
USE_JAVA=	yes

MODULE_PATH=	${PREFIX}/etc/modulefiles/${PKGNAME:C/-${PORTVERSION}.*//}

SUB_FILES=	modulefile
SUB_LIST=	JAVAJARDIR=${JAVAJARDIR} PORTVERSION=${PORTVERSION}

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${MODULE_PATH} \
		${STAGEDIR}${JAVAJARDIR}/${PKGNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/modulefile \
		${STAGEDIR}/${MODULE_PATH}/${PORTVERSION}
	${INSTALL_DATA} ${WRKSRC}/rdp_classifier*.jar \
		${STAGEDIR}${JAVAJARDIR}/${PKGNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${STAGEDIR}${JAVAJARDIR}/${PKGNAME}

.include <bsd.port.mk>
