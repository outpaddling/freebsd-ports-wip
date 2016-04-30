# New ports collection makefile for:	R-studio
# Date created:		2012-03-02
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	rstudio
PORTVERSION=	0.99.1169
CATEGORIES=	math
DISTVERSIONPREFIX=	v

#DISTFILES=	${DISTVERSION}.tar.gz \
#		gin-1.5.zip \
#		gwt-2.4.0.zip \
#		junit-4.9b3.jar
#
#EXTRACT_ONLY=	v${PORTVERSION}

#FETCH_ARGS=	-Fpr 

MAINTAINER=	bacon4000@gmail.com
COMMENT=	GUI for R statistical software

USES=		cmake
USE_ANT=	yes

USE_GITHUB=	yes

CMAKE_ARGS+=	-DDL_LIBRARIES:FILEPATH=/usr/lib \
		-DUUID_LIBRARIES:FILEPATH=/usr/lib

WRKSRC=		${WRKDIR}/rstudio-rstudio-928abf1

BUILD_DEPENDS=	R:${PORTSDIR}/math/R \
		bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	R:${PORTSDIR}/math/R

post-patch:
	${CP} ${DISTDIR}/gin-1.5.zip ${WRKSRC}/dependencies/common
	${CP} ${DISTDIR}/gwt-2.4.0.zip ${WRKSRC}/dependencies/common
	${CP} ${DISTDIR}/junit-4.9b3.jar ${WRKSRC}/dependencies/common
	(cd ${WRKSRC}/dependencies/common && ./install-gwt)

.include <bsd.port.mk>
