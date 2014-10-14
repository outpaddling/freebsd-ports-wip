# Created by: Jason Bacon <bacon@manatee.acadix.biz>
# $FreeBSD$

PORTNAME=	ganglia-web
PORTVERSION=	3.6.2
CATEGORIES=	www
MASTER_SITES=	SF/ganglia/ganglia-web/${PORTVERSION}

MAINTAINER=	bacon@manatee.acadix.biz
COMMENT=

RUN_DEPENDS=	${LOCALBASE}/sbin/gmetad:/usr/wip/sysutils/ganglia-monitor-core

USE_PHP=	gd pcre xml ctype
WANT_PHP_MOD=	yes

post-patch:
	${REINPLACE_CMD} \
		-e 's|/usr/share|${PREFIX}/www|g' \
		-e 's|/etc|${PREFIX}/etc|g' \
		-e 's|www-data|www|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
