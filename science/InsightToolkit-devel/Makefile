# New ports collection Makefile for:   Insight Toolkit
# Date created:        10 Aug 2006
# Whom:                Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD: ports/science/InsightToolkit/Makefile,v 1.2 2007/01/30 04:23:57 kris Exp $
#

PORTNAME=	InsightToolkit
PORTVERSION=	3.4.0
CATEGORIES=	science biology
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	itk

MAINTAINER=	jwbacon@tds.net
COMMENT=	Insight Segmentation and Registration Toolkit

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

OPTIONS=	EXAMPLES "Build examples (very time consuming)" off \
		TESTING  "Build testing programs (very time consuming)" off

USE_LDCONFIG=	${PREFIX}/lib/InsightToolkit
NO_PACKAGE=	License does not allow redistribution of binaries
BUILD_WRKSRC=	${WRKSRC}/Build
INSTALL_WRKSRC=	${BUILD_WRKSRC}

CONFLICTS=	InsightToolkit-2*

CMAKE_ARGS=	-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-DBUILD_SHARED_LIBS:BOOL=ON

SUB_FILES=	pkg-message itk.3

MAN3=		itk.3

.include <bsd.port.pre.mk>

.if !defined(WITH_EXAMPLES)
CMAKE_ARGS+=	"-DBUILD_EXAMPLES:BOOL=OFF"
.endif

.if !defined(WITH_TESTING)
CMAKE_ARGS+=	"-DBUILD_TESTING:BOOL=OFF"
.endif

pre-build:
	@${MKDIR} ${BUILD_WRKSRC}
	@cd ${BUILD_WRKSRC} && cmake ${CMAKE_ARGS} ..

post-install:
	@for lib in ${PREFIX}/lib/InsightToolkit/*.so ; do \
		${LN} -s $$lib.3.4.0 $$lib.3 ; \
	done
	${INSTALL_MAN} ${WRKDIR}/itk.3 ${MAN3PREFIX}/man/man3
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
