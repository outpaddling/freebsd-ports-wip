# New ports collection makefile for:	ape
# Date created:		Nov 2006
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	ape
PORTVERSION=	3.5.2
CATEGORIES=	editors devel
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Another Programmer's Editor

# libtwintk is both a build and run depend.  Ape requires the library and
# headers to build, and libtwintk's terminfo database to run.
BUILD_DEPENDS=	${LOCALBASE}/lib/libpare.a:../../devel/libpare \
		${LOCALBASE}/lib/libbacon.a:../../devel/libbacon \
		${LOCALBASE}/lib/libtwintk.a:../../devel/twintk
RUN_DEPENDS=	${LOCALBASE}/share/twintk/terminfo:../../devel/twintk \
		webbrowser:../../www/webbrowser \
		docviewer:../../textproc/docviewer

USE_XZ=		yes

CONFLICTS=	ape-3.[123]* ape-3.4.[13456789]

# gcc on PowerPC uses unsigned chars by default.  Should be fixed in
# source code now.
# -fsigned-char
CFLAGS=		-g -Wall

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.pre.mk>

.if defined(WITH_RXVT)
RUN_DEPENDS+=	rxvt:${PORTSDIR}/x11/rxvt
.endif

pre-build:
	(cd ${WRKSRC} && make depend)

.include <bsd.port.post.mk>
