# $FreeBSD$

PORTNAME=		ad2vcf
DISTVERSION=		0.1.1-65
DISTVERSIONSUFFIX=	-ga23ca09
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Add allelic depth info from a SAM stream to a VCF file

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	biolibc>=0.1.1:wip/biolibc

USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

PLIST_FILES=	bin/ad2vcf man/man1/ad2vcf.1.gz

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
