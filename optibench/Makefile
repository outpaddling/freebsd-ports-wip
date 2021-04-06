
PORTNAME=	OptiBench
DISTVERSION=	0.2.0-1
DISTVERSIONSUFFIX=	-g2879781
CATEGORIES=	wip benchmarks

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Measure optimal sustained memory and disk performance

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

MAKE_ARGS+=	PREFIX=${STAGEDIR}${PREFIX} MANPREFIX=${STAGEDIR}${MANPREFIX}

PLIST_FILES=	bin/optibench man/man1/optibench.1.gz

.include <bsd.port.mk>
