# $FreeBSD$

PORTNAME=		bioawk
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0-7
DISTVERSIONSUFFIX=	-gfd40150
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	BWK awk modified for biological data

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes

GH_ACCOUNT=	lh3

ALL_TARGET=		# empty
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/bioawk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bioawk ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
