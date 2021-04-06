
PORTNAME=	dosu
PORTVERSION=	0.1
CATEGORIES=	wip sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Run commands as another user

MAN1=		dosu.1

post-extract:
	${REINPLACE_CMD} -e 's|PREFIX|${PREFIX}|g' ${WRKSRC}/dosu.1

.include <bsd.port.mk>
