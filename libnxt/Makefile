# New ports collection makefile for:	libnxt
# Date created:		2007-05-05
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libnxt
PORTVERSION=	0.3
CATEGORIES=	wip devel
MASTER_SITES=	http://libnxt.googlecode.com/files/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Lego NXT library

BUILD_DEPENDS=	scons:devel/scons \
		python:lang/python

SUB_FILES=	pkg-message

do-build:
	(cd ${WRKSRC}; scons)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/libnxt
	${INSTALL_PROGRAM} ${WRKSRC}/fwflash ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fwexec ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libnxt.a ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/include/libnxt
.for file in ${WRKSRC}/*.h
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/include/libnxt
.endfor

post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.mk>
