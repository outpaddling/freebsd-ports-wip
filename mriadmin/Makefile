
PORTNAME=	mriadmin
PORTVERSION=	0.1
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	wip science
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	MRI system admin tool

MAN1=		mriadmin.1

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/dotcshrc
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/csh.cshrc
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/dotcshrc
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/csh.cshrc

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
