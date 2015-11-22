# New ports collection makefile for:    libtwin
# Date created:         Nov 2006
# Whom:                 Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=       twintk
PORTVERSION=    0.9.4
CATEGORIES=     devel
MASTER_SITES=   http://acadix.biz/Ports/distfiles/

MAINTAINER=     bacon4000@gmail.com
COMMENT=        Misc functions

USES=		tar:xz

BUILD_DEPENDS=  ${LOCALBASE}/lib/libbacon.a:/usr/wip/devel/libbacon

CFLAGS=         -g -Wall

CONFLICTS=      libtwin-[0-9]* twintk-0.9.[13456789]

# Makefile uses PREFIX to determine location of terminfo db, so it should be
# the final destination, not the staged.
INSTALL_TARGET= PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX} \
		install

.include <bsd.port.mk>
