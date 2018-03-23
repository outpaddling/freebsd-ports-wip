# $FreeBSD$

PORTNAME=	SeqLib
PORTVERSION=	2018.03.23
CATEGORIES=	wip biology
MASTER_SITES=	https://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C++ htslib/bwa-mem/fermi interface for interrogating sequence data

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	fermi-lite-walaj>=0:wip/fermi-lite-walaj

USES=		gmake tar:xz
USE_GCC=	yes

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
