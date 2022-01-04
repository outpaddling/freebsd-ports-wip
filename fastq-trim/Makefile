PORTNAME=	fastq-trim
DISTVERSION=	0.0.0-15
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lightening fast sequence read trimmer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbiolibc.so:wip/biolibc

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_TAGNAME=	9fbb2d5c4c674a7d493482f9f396cd4665abba30

PLIST_FILES=	bin/fastq-trim bin/fastq-vis \
		man/man1/fastq-trim.1.gz man/man1/fastq-vis.1.gz

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
