
PORTNAME=	ddclone
PORTVERSION=	0.1
CATEGORIES=	wip sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Removable media eject

MAN1=		ddclone.1
MANCOMPRESSED=	yes

NO_BUILD=	yes

PLIST_FILES=	sbin/ddclone

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ddclone ${PREFIX}/sbin/ddclone
	${INSTALL_MAN} ${WRKSRC}/ddclone.1 ${PREFIX}/man/man1
	${GZIP_CMD} -best ${PREFIX}/man/man1/ddclone.1

.include <bsd.port.mk>
