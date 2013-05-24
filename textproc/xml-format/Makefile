# Created by:	Jason Bacon
# $FreeBSD$

PORTNAME=	xml-format
PORTVERSION=	0.1
CATEGORIES=	textproc
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	XML beautifier

LICENSE=	BSD

MAN1=		xml-format.1

MAKE_ENV+=	DATADIR=${DATADIR}

post-patch:
	${REINPLACE_CMD} -e "s|DATADIR|${DATADIR}|g" ${WRKSRC}/${PORTNAME}.1

.include <bsd.port.mk>
