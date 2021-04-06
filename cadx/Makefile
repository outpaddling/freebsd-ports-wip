
PORTNAME=	ginkgocadx
PORTVERSION=	3.3.0
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=
# http://heanet.dl.sourceforge.net/project/ginkgocadx/ginkgocadx/3.3.0/ginkgocadx-3.3.0.757.27.tar.gz
MASTER_SITES=	SF/ginkgocadx/3.3.0/
DISTNAME=	${PORTNAME}-${PORTVERSION}.757.27

MAINTAINER=	jwb@FreeBSD.org
COMMENT=

WRKSRC=		${WRKDIR}/srcpkg/${DISTNAME}/src/
USE_CMAKE=	yes

FETCH_ARGS+=	-F

post-patch:
	${CP} ${WRKSRC}/CMake/LinuxProperties.cmake \
		${WRKSRC}/CMake/FreeBSDProperties.cmake

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
