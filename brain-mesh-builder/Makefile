PORTNAME=	brain-mesh-builder
DISTVERSIONPREFIX=	v.
DISTVERSION=	1.0
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Surface mesh building based on 3-dimensional image stacks
WWW=		https://github.com/hwm2746/brain-mesh-builder/releases

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GCC=	yes
USE_GITHUB=	yes

GH_ACCOUNT=	hwm2746

PLIST_FILES=	bin/dodri

pre-build:
	${RM} ${WRKSRC}/bin/* ${WRKSRC}/obj/*.o ${WRKSRC}/obj/io/*.o

.include <bsd.port.mk>
