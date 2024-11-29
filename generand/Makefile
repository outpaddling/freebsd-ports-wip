PORTNAME=	generand
DISTVERSION=	0.1.2-8
DISTVERSIONSUFFIX=	-ga715a89
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Generate random genomic data in FASTA/FASTQ, SAM, or VCF format
WWW=		https://github.com/auerlab/generand

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

MAKE_ARGS+=	MANDIR=${PREFIX}/share/man VERSION=${PORTVERSION}

PLIST_FILES=	bin/generand share/man/man1/generand.1.gz

.include <bsd.port.mk>
