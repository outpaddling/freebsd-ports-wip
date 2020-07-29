# $FreeBSD$

PORTNAME=		ad2vcf
DISTVERSION=		0.1.1-45
DISTVERSIONSUFFIX=	-g32c247f
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Add allelic depth info from a SAM stream to a VCF file

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	biolibc>=0.1.0:wip/biolibc

USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

PLIST_FILES=	bin/ad2vcf

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
