PORTNAME=	fastq-trim
DISTVERSION=	0.0.0-38
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lightening fast sequence read trimmer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbiolibc.so:wip/biolibc libxtend.so:wip/libxtend

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_TAGNAME=	6710157c4107d82142699aee98acab23561ceaa9

PLIST_FILES=	bin/fastq-trim bin/fastq-vis \
		man/man1/fastq-trim.1.gz man/man1/fastq-vis.1.gz

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
