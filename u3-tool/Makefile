PORTNAME=	u3-tool
PORTVERSION=	0.3
CATEGORIES=	wip
MASTER_SITES=	SF

MAINTAINER=	bacon@mako.acadix.biz
COMMENT=	Manage u3 partition on USB drive

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

LDFLAGS+=	-lusb

PLIST_FILES=	man/man1/u3-tool.1.gz sbin/u3-tool

.include <bsd.port.mk>
