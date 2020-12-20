# Created by: ijliao
# $FreeBSD$

PORTNAME=	awka
PORTVERSION=	0.7.5.23
CATEGORIES=	wip lang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts the AWK script to C, then compiles it

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL.txt

USES=		desthack
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

GH_ACCOUNT=	noyesno
GH_TAGNAME=	524a3fb

CFLAGS+=	-Wno-pointer-sign

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/awka \
		${STAGEDIR}${PREFIX}/lib/libawka.so

do-test:
	(cd ${WRKSRC} && ${MAKE} test)

.include <bsd.port.mk>
