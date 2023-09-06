PORTNAME=	vcf-split
DISTVERSION=	0.1.5-10
DISTVERSIONSUFFIX=	-g0f2fd0a
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Split a multi-sample VCF into single-sample VCFs
WWW=		https://github.com/auerlab/vcf-split

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbiolibc.so:wip/biolibc libxtend.so:wip/libxtend

USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

MAKE_ENV=	VERSION=${PORTVERSION}
PLIST_FILES=	bin/vcf-split man/man1/vcf-split.1.gz

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
