PORTNAME=	vcf-split
DISTVERSION=	0.1.5-19
DISTVERSIONSUFFIX=	-g1a8ab82
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Split a multi-sample VCF into single-sample VCFs
WWW=		https://github.com/auerlab/vcf-split

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbiolibc.so:wip/biolibc libxtend.so:wip/libxtend

USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

MAKE_ARGS=	MANDIR=${PREFIX}/share/man VERSION=${PORTVERSION}
PLIST_FILES=	bin/vcf-split share/man/man1/vcf-split.1.gz

.include <bsd.port.mk>
