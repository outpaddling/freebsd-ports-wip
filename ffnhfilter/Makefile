PORTNAME=	ffnhfilter
PORTVERSION=	1.0
CATEGORIES=	wip science
MASTER_SITES=	http://www.neuro.mcw.edu/~bacon/Ports/distfiles/ \
		http://bacon.is-a-geek.org/~bacon/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Extract  3Ddump  data in the vicinity of specified locations

BUILD_DEPENDS=	${LOCALBASE}/lib/libbacon.a:../../devel/libbacon \
		${LOCALBASE}/lib/libFFMap.a:../../science/libffmap

PLIST_FILES=	bin/ffnhfilter

MAN1=		ffnhfilter.1

.include <bsd.port.mk>
