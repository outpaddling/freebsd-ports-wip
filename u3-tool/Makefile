PORTNAME=	u3-tool
PORTVERSION=	0.3
CATEGORIES=	wip
MASTER_SITES=	SF

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Manage u3 partition on USB drive
WWW=		https://u3-tool.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

LDFLAGS+=	-lusb

PLIST_FILES=	man/man1/u3-tool.1.gz sbin/u3-tool

.include <bsd.port.mk>
