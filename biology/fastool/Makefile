# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	fastool
PORTVERSION=	0.1.4
CATEGORIES=	biology
MASTER_SITES=	http://github.com/fstrozzi/Fastool/archive/
DISTNAME=	${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Simple and quick FastQ and FastA tool for file reading and conversion

LICENSE=	BSD2CLAUSE

WRKSRC=		${WRKDIR}/Fastool-${PORTVERSION}

post-patch:
	${REINPLACE_CMD} \
		-e 's|CC *=|CC ?=|g' \
		-e 's|CFLAGS *=|CFLAGS ?=|g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fastool \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
