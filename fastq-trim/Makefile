PORTNAME=	fastq-trim
DISTVERSION=	0.1.3-11
DISTVERSIONSUFFIX=	-g505ca26
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lightening fast sequence read trimmer
WWW=		https://github.com/outpaddling/Fastq-trim

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:wip/libxtend libbiolibc.so:wip/biolibc

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

MAKE_ARGS=	MANPREFIX=${PREFIX}/share VERSION=${PORTVERSION}

.include <bsd.port.mk>
