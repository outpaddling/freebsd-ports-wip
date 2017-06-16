# New ports collection makefile for:	mriadmin
# Date created:		2008-11-13
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mriadmin
PORTVERSION=	0.1
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	wip science
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	MRI system admin tool

MAN1=		mriadmin.1

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/dotcshrc
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/csh.cshrc
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/dotcshrc
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/csh.cshrc

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
