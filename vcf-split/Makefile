# $FreeBSD$

PORTNAME=	vcf-split
DISTVERSION=	g20200122
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Split a multi-sample VCF into single-sample VCFs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libvcfio.a:wip/vcfio

USE_GITHUB=	yes
GH_ACCOUNT=	auerlab
GH_TAGNAME=	3bdcd1da

PLIST_FILES=	bin/vcf-split man/man1/vcf-split.1.gz

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
