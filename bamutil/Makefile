PORTNAME=	bamutil
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.15
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Utilities for working with SAM/BAM files
WWW=		https://github.com/statgen/bamUtil

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/copyrights/COPYING

USES=		gmake
USE_GITHUB=	yes

GH_ACCOUNT=	statgen
GH_PROJECT=	bamUtil

# Build needs access to libStatGen Makefiles, so can't install separately
GH_TUPLE=	statgen:libStatGen:v${DISTVERSION}:statgen/libStatGen

MAKE_ENV=	LIB_PATH_GENERAL=${WRKSRC}/libStatGen
MAKE_ENV+=	INSTALLDIR=${STAGEDIR}${PREFIX}/bin

PLIST_FILES=	bin/bam

.include <bsd.port.mk>
