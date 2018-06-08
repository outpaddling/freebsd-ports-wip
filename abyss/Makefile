# $FreeBSD$

PORTNAME=	abyss
PORTVERSION=	2.1.0
CATEGORIES=	wip

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Assemble large genomes using short reads

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	sparsehash>0:devel/sparsehash
LIB_DEPENDS=	libmpi.so:net/openmpi \
		libboost_system.so:devel/boost-libs
USES=		autoreconf compiler:openmp
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	bcgsc

.include <bsd.port.mk>
