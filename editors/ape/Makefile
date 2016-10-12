# New ports collection makefile for:	ape
# Date created:		Nov 2006
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ape
PORTVERSION=	3.5.2
CATEGORIES=	editors devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Another Programmer's Editor

# Match this to libs
LICENSE=	BSD2CLAUSE

# libtwintk is both a build and run depend.  Ape requires the library and
# headers to build, and libtwintk's terminfo database to run.
BUILD_DEPENDS=	${LOCALBASE}/lib/libpare.a:${PORTSDIR}/../wip/devel/libpare \
		${LOCALBASE}/lib/libbacon.a:${PORTSDIR}/../wip/devel/libbacon \
		${LOCALBASE}/lib/libtwintk.a:${PORTSDIR}/../wip/devel/twintk
RUN_DEPENDS=	${LOCALBASE}/share/twintk/terminfo/README:${PORTSDIR}/../wip/devel/twintk \
		webbrowser:${PORTSDIR}/../wip/www/webbrowser \
		docviewer:${PORTSDIR}/../wip/textproc/docviewer

USES=		tar:xz

CONFLICTS=	ape-3.[01234]* ape-3.5.[01]

# gcc on PowerPC uses unsigned chars by default.  Should be fixed in
# source code now.
# -fsigned-char
CFLAGS=		-g -Wall

MAKE_FLAGS+=	PREFIX=${PREFIX} \
		MANPREFIX=${PREFIX} \
		DATADIR=${DATADIR} \
		DOCSDIR=${DOCSDIR} \
		STAGEDIR=${STAGEDIR}

.include <bsd.port.pre.mk>

.if defined(WITH_RXVT)
RUN_DEPENDS+=	rxvt:x11/rxvt
.endif

pre-build:
	(cd ${WRKSRC} && make depend)

.include <bsd.port.post.mk>
