PORTNAME=	vcf-split
DISTVERSION=	0.1.4-2
DISTVERSIONSUFFIX=	-g82657a5
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Split a multi-sample VCF into single-sample VCFs

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
