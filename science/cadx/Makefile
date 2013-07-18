# New ports collection makefile for:	ginkgo
# Date created:		2013-07-11
# Whom:			Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	ginkgocadx
PORTVERSION=	3.3.0
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=
# http://heanet.dl.sourceforge.net/project/ginkgocadx/ginkgocadx/3.3.0/ginkgocadx-3.3.0.757.27.tar.gz
MASTER_SITES=	SF/ginkgocadx/3.3.0/
DISTNAME=	${PORTNAME}-${PORTVERSION}.757.27

MAINTAINER=	bacon@sculpin.jbacon.dyndns.org
COMMENT=

WRKSRC=		${WRKDIR}/srcpkg/${DISTNAME}/src/
USE_CMAKE=	yes

FETCH_ARGS+=	-F

post-patch:
	${CP} ${WRKSRC}/CMake/LinuxProperties.cmake \
		${WRKSRC}/CMake/FreeBSDProperties.cmake

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
