# $FreeBSD$

PORTNAME=	vcf-split
DISTVERSION=	g20200219
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Split a multi-sample VCF into single-sample VCFs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	vcfio>=g20200219:wip/vcfio

USE_GITHUB=	yes
GH_ACCOUNT=	auerlab
GH_TAGNAME=	66e6c50d

PLIST_FILES=	bin/vcf-split man/man1/vcf-split.1.gz

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
