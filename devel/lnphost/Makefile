# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	lnphost
PORTVERSION=	1.0a
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	jwbacon@tds.net
COMMENT=	Lego RCX iinfrared communication API

LICENSE=	GPLv2

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
