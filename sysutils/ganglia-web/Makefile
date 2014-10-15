# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

# Note: /var/lib/ganglia-web must be owned by www.  Add the following to
# the top of pkg-plist:
#
# @owner %%WWWOWN%%
# @group %%WWWGRP%%

PORTNAME=	ganglia-web
PORTVERSION=	3.6.2
CATEGORIES=	sysutils www
MASTER_SITES=	SF/ganglia/ganglia-web/${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Ganglia network monitor web interface

RUN_DEPENDS=	${LOCALBASE}/sbin/gmetad:${PORTSDIR}/sysutils/ganglia-monitor-core

USE_PHP=	gd pcre xml ctype session filter
WANT_PHP_MOD=	yes

WEBDIR=		www/ganglia

PLIST_SUB+=     WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/usr/share/ganglia-webfrontend|${PREFIX}/${WEBDIR}|g' \
		-e 's|/etc|${PREFIX}/etc|g' \
		-e 's|www-data|www|g' \
		-e 's|/var/lib/ganglia|/var/db/ganglia|g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} \
		-e 's|/usr/bin/rrdtool|${PREFIX}/bin/rrdtool|g' \
		-e 's|/var/lib/ganglia|/var/db/ganglia|g' \
		${WRKSRC}/conf_default.php*

.include <bsd.port.mk>
