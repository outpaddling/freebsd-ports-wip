# New ports collection makefile for:    libtwin
# Date created:         Nov 2006
# Whom:                 Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=       twintk
PORTVERSION=    0.9.4
CATEGORIES=     devel
MASTER_SITES=   http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=     jwbacon@tds.net
COMMENT=        Misc functions

BUILD_DEPENDS=  ${LOCALBASE}/lib/libbacon.a:../../devel/libbacon

CFLAGS=         -g -Wall

CONFLICTS=      libtwin-[0-9]* twintk-0.9.[13456789]

# Makefile uses PREFIX to determine location of terminfo db, so it should be
# the final destination, not the staged.
INSTALL_TARGET= PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX} \
		install

.include <bsd.port.mk>
