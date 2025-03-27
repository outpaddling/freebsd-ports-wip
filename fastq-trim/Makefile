PORTNAME=	fastq-trim
DISTVERSION=	0.1.3-16
DISTVERSIONSUFFIX=	-g165a5ec
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lightening fast sequence read trimmer
WWW=		https://github.com/outpaddling/Fastq-trim

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	biolibc>=0.2.6.10:wip/biolibc
LIB_DEPENDS=	libxtend.so:wip/libxtend libbiolibc.so:wip/biolibc

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

MAKE_ARGS=	MANPREFIX=${PREFIX}/share VERSION=${PORTVERSION}

.include <bsd.port.mk>
