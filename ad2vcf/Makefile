PORTNAME=	ad2vcf
DISTVERSION=	0.1.6-20
DISTVERSIONSUFFIX=	-g51c419e
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Add allelic depth info from a SAM stream to a VCF file
WWW=		https://github.com/auerlab/ad2vcf

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbiolibc.so:wip/biolibc libxtend.so:wip/libxtend

USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

MAKE_ARGS=	MANPREFIX=${PREFIX}/share
MAKE_ENV+=	VERSION=${PORTVERSION}
PLIST_FILES=	bin/ad2vcf share/man/man1/ad2vcf.1.gz

do-test:
	(cd ${WRKSRC}/Test && ./run-test.sh)

.include <bsd.port.mk>
