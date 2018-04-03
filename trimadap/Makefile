# $FreeBSD$

PORTNAME=	trimadap
PORTVERSION=	0.1p20170211
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Trim adapter sequences from Illumina data using heuristic rules

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	lh3
GH_TAGNAME=	ddfef210563830d9193b40949da3523b6fb93003

PLIST_FILES=	bin/trimadap-mt

#.include <bsd.port.pre.mk>

CFLAGS_i386+=	-msse2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trimadap-mt ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
