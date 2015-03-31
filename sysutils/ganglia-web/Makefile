# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	ganglia-web
PORTVERSION=	3.6.2
CATEGORIES=	sysutils net www
MASTER_SITES=	SF/ganglia/ganglia-web/${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Ganglia network monitor web interface

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	gmetad:${PORTSDIR}/sysutils/ganglia-monitor-core

PKGINSTALL=	${WRKDIR}/pkg-install

USE_PHP=	gd pcre xml ctype session filter
WANT_PHP_MOD=	yes

HTMLDIR=	www/ganglia

# DO NOT DELETE!!
# HTMLDIR and GWEBDIR must be owned by WWWOWN:WWWGRP.
# Add the following to pkg-plist:
# @owner %%WWWOWN%%
# @group %%WWWGRP%%

PLIST_SUB+=	WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP}
SUB_LIST+=	STAGEDIR=${STAGEDIR} \
		WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP} \
		GWEBDIR=${GWEBDIR}

SUB_FILES+=	pkg-install

# Taken from ganglia-monitor-core.  Must match for ganglia-web to function!
# Content of these directories should not be touched by deinstall.  It
# contains history and must remain intact through an upgrade.
RRD_ROOTDIR=	/var/db/ganglia
GWEBDIR=	${RRD_ROOTDIR}-web

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/usr/share/ganglia-webfrontend|${PREFIX}/${HTMLDIR}|g' \
		-e 's|/etc|${PREFIX}/etc|g' \
		-e 's|www-data|www|g' \
		-e 's|/var/lib/ganglia-web|${GWEBDIR}|g' \
		-e 's|/var/lib/ganglia|${RRD_ROOTDIR}|g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} \
		-e 's|/usr/bin/rrdtool|${LOCALBASE}/bin/rrdtool|g' \
		-e 's|/var/lib/ganglia-web|${GWEBDIR}|g' \
		-e 's|/var/lib/ganglia|${RRD_ROOTDIR}|g' \
		${WRKSRC}/conf_default.php*

.include <bsd.port.mk>
