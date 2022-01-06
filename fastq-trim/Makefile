PORTNAME=	fastq-trim
DISTVERSION=	0.0.0-26
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lightening fast sequence read trimmer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbiolibc.so:wip/biolibc libxtend.so:wip/libxtend

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_TAGNAME=	9b243fb4e65ff221496c004674bb3b403195c0b5

PLIST_FILES=	bin/fastq-trim bin/fastq-vis \
		man/man1/fastq-trim.1.gz man/man1/fastq-vis.1.gz

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
