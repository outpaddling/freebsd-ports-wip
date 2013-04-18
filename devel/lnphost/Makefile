# New ports collection makefile for:	lnphost
# Date created:		2007-09-13
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	lnphost
PORTVERSION=	1.0a
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	jwbacon@tds.net
COMMENT=	Lego RCX API

USE_ZIP=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/lnphost
CFLAGS+=	-DHAVE_STRING_H

PLIST_FILES=	bin/lnpdump \
		lib/lnphost.a \
		include/lnphost.h

MAN1=		lnpdump.1

# Use system getopt
post-patch:
	${RM} ${WRKSRC}/Include/getopt.h ${WRKSRC}/Modules/getopt.c

.include <bsd.port.mk>
