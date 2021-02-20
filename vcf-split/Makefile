# $FreeBSD$

PORTNAME=		vcf-split
DISTVERSION=		0.1.0-15
DISTVERSIONSUFFIX=	-g5f727d7
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Split a multi-sample VCF into single-sample VCFs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	biolibc>=0.1.0:wip/biolibc

USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

PLIST_FILES=	bin/vcf-split man/man1/vcf-split.1.gz

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
