# New ports collection makefile for:	ffnhfilter
# Date created:		4 jan 2007
# Whom:			Jason W. Bacon
#
# $FreeBSD$
#

PORTNAME=	ffnhfilter
PORTVERSION=	1.0
CATEGORIES=	science
MASTER_SITES=	http://www.neuro.mcw.edu/~bacon/Ports/distfiles/ \
		http://bacon.is-a-geek.org/~bacon/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Extract  3Ddump  data in the vicinity of specified locations

BUILD_DEPENDS=	${LOCALBASE}/lib/libbacon.a:../../devel/libbacon \
		${LOCALBASE}/lib/libFFMap.a:../../science/libffmap

PLIST_FILES=	bin/ffnhfilter

MAN1=		ffnhfilter.1

.include <bsd.port.mk>
