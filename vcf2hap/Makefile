# Created by: Jason Bacon <jwb@FreeBSD.org>

PORTNAME=	vcf2hap
DISTVERSION=	0.1.2-5
DISTVERSIONSUFFIX=	-g77d952d
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Generate .hap file from VCF for haplohseq

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbiolibc.so:wip/biolibc libxtend.so:wip/libxtend

USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

PLIST_FILES=	bin/vcf2hap man/man1/vcf2hap.1.gz

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

do-test:
	(cd ${WRKSRC}/Test && ./run-test.sh)

.include <bsd.port.mk>
