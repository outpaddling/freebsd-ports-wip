PORTNAME=	pbs-scripts
PORTVERSION=	0.1
CATEGORIES=	wip sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Supplemental scripts for PBS scheduler
WWW=		https://port.home.page/

NO_BUILD=	yes

PLIST_FILES=	bin/qpeek bin/qsub-cmd

MAN1=		qpeek.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Man/qpeek.man ${PREFIX}/man/man1/qpeek.1

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
