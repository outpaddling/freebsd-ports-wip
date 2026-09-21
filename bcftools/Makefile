PORTNAME=	bcftools
PORTVERSION=	1.24
CATEGORIES=	wip biology
MASTER_SITES=	https://github.com/samtools/bcftools/releases/download/1.24/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for manipulating next-generation sequencing data
WWW=		https://www.htslib.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	htslib>=1.24:wip/htslib
LIB_DEPENDS=	libhts.so:wip/htslib libdeflate.so:archivers/libdeflate libcurl.so:ftp/curl
TEST_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake localbase python:env shebangfix ssl tar:bzip2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
SHEBANG_FILES=	misc/* test/test.pl

OPTIONS_DEFINE=		GPL PERL
GPL_DESC=		Enable modules that rely on GPL code
PERL_DESC=		Enable external PERL scripts for advanced filtering
OPTIONS_DEFAULT=	GPL PERL

GPL_LIB_DEPENDS=	libgsl.so:math/gsl
GPL_CONFIGURE_ENABLE=	libgsl
PERL_USES=		perl5
PERL_CONFIGURE_ENABLE=	perl-filters

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGPL}
MAKE_ENV+=	USE_GPL=1
LICENSE+=	GPLv3
LICENSE_COMB=	multi
.endif

TEST_TARGET=	test

pre-configure:
	@${REINPLACE_CMD} -e 's|@PORTVERSION@|${PORTVERSION}|g' \
		${WRKSRC}/configure.ac

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/color-chrs.pl \
		${STAGEDIR}${PREFIX}/bin/color-chrs
	${MV} ${STAGEDIR}${PREFIX}/bin/guess-ploidy.py\
	       ${STAGEDIR}${PREFIX}/bin/guess-ploidy
	${MV} /${STAGEDIR}${PREFIX}/bin/plot-roh.py \
		${STAGEDIR}${PREFIX}/bin/plot-roh
	${MV} ${STAGEDIR}${PREFIX}/bin/run-roh.pl \
		${STAGEDIR}${PREFIX}/bin/run-roh
	${MV} ${STAGEDIR}${PREFIX}/bin/vcfutils.pl \
		${STAGEDIR}${PREFIX}/bin/vcfutils
	${MV} ${STAGEDIR}${PREFIX}/bin/plot-vcfstats \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
