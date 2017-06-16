# New ports collection makefile for:	pbs-scripts
# Date created:		2012-01-27
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pbs-scripts
PORTVERSION=	0.1
CATEGORIES=	wip sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Supplemental scripts for PBS scheduler

NO_BUILD=	yes

PLIST_FILES=	bin/qpeek bin/qsub-cmd

MAN1=		qpeek.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Man/qpeek.man ${PREFIX}/man/man1/qpeek.1

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
