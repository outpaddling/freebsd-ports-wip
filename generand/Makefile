# $FreeBSD$

PORTNAME=		generand
DISTVERSION=		0.1-3
DISTVERSIONSUFFIX=	-g477de38
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Generate random genomic data in FASTA/FASTQ, SAM, or VCF format

LICENSE=	BSD2CLAUSE
# LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

PLIST_FILES=	bin/generand

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
