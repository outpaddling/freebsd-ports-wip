# Created by: ijliao
# $FreeBSD: head/lang/awka/Makefile 405891 2016-01-12 16:20:31Z amdmi3 $

PORTNAME=	awka
PORTVERSION=	0.7.5.20
CATEGORIES=	wip lang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts the AWK script to C, then compiles it

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL.txt

GNU_CONFIGURE=	yes

USES=		desthack
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	noyesno
GH_TAGNAME=	1337789

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/awka \
		${STAGEDIR}${PREFIX}/lib/libawka.so

do-test:
	(cd ${WRKSRC} && ${MAKE} test)

.include <bsd.port.mk>
