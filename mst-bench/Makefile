PORTNAME=	MST-Bench
DISTVERSION=	0.2.0-13
DISTVERSIONSUFFIX=	-g39f2d67
CATEGORIES=	wip benchmarks

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Measure optimal sustained memory and disk performance

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

MAKE_ARGS+=	PREFIX=${STAGEDIR}${PREFIX} MANPREFIX=${STAGEDIR}${MANPREFIX}

PLIST_FILES=	bin/mst-bench man/man1/mst-bench.1.gz

.include <bsd.port.mk>
