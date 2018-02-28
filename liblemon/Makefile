# $FreeBSD$

PORTNAME=	liblemon
PORTVERSION=	1.3.1
CATEGORIES=	wip science
MASTER_SITES=	http://lemon.cs.elte.hu/pub/sources/
DISTNAME=	lemon-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Library for Efficient Modeling and Optimization in Networks

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libglpk.so:math/glpk

USES=		cmake:outsource shebangfix
SHEBANG_FILES=	scripts/unify-sources.sh tools/lemon-0.x-to-1.x.sh


.include <bsd.port.mk>
