PORTNAME=	fakechroot
DISTVERSION=	2.20.1
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Simulate chroot(8) without root privileges
WWW=		https://example.com/fakechroot

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfakeroot.so:security/fakeroot

USE_GITHUB=	yes

GH_ACCOUNT=	dex4er

GNU_CONFIGURE=	yes

CFLAGS+=	-DHAVE___OPENDIR2

.include <bsd.port.mk>
