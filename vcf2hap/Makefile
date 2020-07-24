# $FreeBSD$

PORTNAME=		vcf2hap
DISTVERSION=		0.1.1-16
DISTVERSIONSUFFIX=	-g7926cba
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Generate .hap file from VCF for haplohseq

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	biolibc>=0.1.0:wip/biolibc

USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

PLIST_FILES=	bin/vcf2hap

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
