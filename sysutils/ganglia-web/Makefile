# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	ganglia-web
PORTVERSION=	3.6.2
CATEGORIES=	sysutils www
MASTER_SITES=	SF/ganglia/ganglia-web/${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Ganglia network monitor web interface

RUN_DEPENDS=	${LOCALBASE}/sbin/gmetad:${PORTSDIR}/sysutils/ganglia-monitor-core

USE_PHP=	gd pcre xml ctype
WANT_PHP_MOD=	yes

WEBDIR=		www/ganglia

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/usr/share/ganglia-webfrontend|${PREFIX}/${WEBDIR}|g' \
		-e 's|/etc|${PREFIX}/etc|g' \
		-e 's|www-data|www|g' \
		${WRKSRC}/Makefile

# /var/lib/ganglia-web must be owned by www
# /var/lib/ganglia must be owned by ganglia
post-install:
        @${CHOWN} -Rh ${WWWOWN}:${WWWGRP} ${STAGEDIR}${PREFIX}/${WEBDIR}

.include <bsd.port.mk>
