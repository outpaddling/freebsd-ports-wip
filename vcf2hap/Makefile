PORTNAME=	vcf2hap
DISTVERSION=	0.1.6-14
DISTVERSIONSUFFIX=	-g8f39985
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Generate .hap file from VCF for haplohseq
WWW=		https://github.com/auerlab/vcf2hap

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbiolibc.so:wip/biolibc libxtend.so:wip/libxtend

USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

MAKE_ARGS=	MANDIR=${PREFIX}/share/man VERSION=${PORTVERSION}
PLIST_FILES=	bin/vcf2hap share/man/man1/vcf2hap.1.gz

do-test:
	(cd ${WRKSRC}/Test && ./run-test.sh)

.include <bsd.port.mk>
