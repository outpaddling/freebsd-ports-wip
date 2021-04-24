# $FreeBSD$

PORTNAME=	peak-classifier
DISTVERSION=	0.0.1-1
DISTVERSIONSUFFIX=	-g42d3ded
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Classify ChIP/ATAC-Seq peaks based on features provided in a GFF

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	biolibc>=0.1.1.14:wip/biolibc

USES=		localbase

USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

PLIST_FILES=	bin/peak-classifier \
		man/man1/peak-classifier.1.gz

pre-build:
	cd ${WRKSRC} && make depend LOCALBASE=${LOCALBASE}

.include <bsd.port.mk>
