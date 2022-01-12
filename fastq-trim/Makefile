PORTNAME=	fastq-trim
DISTVERSION=	0.0.0-51
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lightening fast sequence read trimmer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbiolibc.so:wip/biolibc libxtend.so:wip/libxtend

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_TAGNAME=	78bddbf4f5de2e9dd0beae2eae5294199e996377

PLIST_FILES=	bin/fastq-trim bin/fastq-vis \
		man/man1/fastq-trim.1.gz man/man1/fastq-vis.1.gz

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
