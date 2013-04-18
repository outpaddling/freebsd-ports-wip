# New ports collection makefile for:	ffsectorstats
# Date created:		4 jan 2007
# Whom:			Jason W. Bacon
#
# $FreeBSD$
#

PORTNAME=	ffsectorstats
PORTVERSION=	1.0
CATEGORIES=	science
MASTER_SITES=	http://www.neuro.mcw.edu/~bacon/Ports/distfiles/ \
		http://bacon.is-a-geek.org/~bacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Process visual data by sectors

BUILD_DEPENDS=	${LOCALBASE}/lib/libbacon.a:../../devel/libbacon \
		${LOCALBASE}/lib/libFFMap.a:../../science/libffmap

PLIST_FILES=	bin/ffsectorstats

MAN1=		ffsectorstats.1

.include <bsd.port.mk>
