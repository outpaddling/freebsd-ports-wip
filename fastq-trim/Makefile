PORTNAME=	fastq-trim
DISTVERSION=	0.1.2-6
DISTVERSIONSUFFIX=	-g9fb5d1f
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lightening fast sequence read trimmer
WWW=		https://github.com/outpaddling/Fastq-trim

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbiolibc.so:wip/biolibc libxtend.so:wip/libxtend

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

MAKE_ENV=	VERSION=${PORTVERSION}

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
