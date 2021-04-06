# Created by: ijliao

PORTNAME=	awka
PORTVERSION=	0.7.5.26
CATEGORIES=	wip lang

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Converts the AWK script to C, then compiles it

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL.txt

USES=		desthack
USE_GITHUB=	yes

GNU_CONFIGURE=	yes

GH_ACCOUNT=	outpaddling
GH_TAGNAME=	e27b5be

CFLAGS+=	-Wno-pointer-sign

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/awka \
		${STAGEDIR}${PREFIX}/lib/libawka.so

do-test:
	(cd ${WRKSRC} && ${MAKE} test)

.include <bsd.port.mk>
