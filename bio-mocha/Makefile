PORTNAME=	bio-mocha
DISTVERSION=	1.13
CATEGORIES=	wip biology
MASTER_SITES=	https://software.broadinstitute.org/software/mocha/
DISTFILES+=	${PORTNAME}_${DISTVERSION}-20211015.tar.gz

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Mosaic chromosomal alterations detection and analysis

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhts.so:biology/htslib
BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bcftools==${PORTVERSION}:biology/bcftools

USES=		autoreconf gmake localbase perl5 python:env shebangfix
USE_GITHUB=	yes
USE_PERL5=	test

GH_ACCOUNT=	samtools
GH_PROJECT=	bcftools
GNU_CONFIGURE=	yes
SHEBANG_FILES=	misc/* test/test.pl

PLIST_FILES=	\
	libexec/bcftools/extendFMT.so \
	libexec/bcftools/mocha.so \
	libexec/bcftools/mochatools.so \
	libexec/bcftools/score.so \
	libexec/bcftools/trio-phase.so

TEST_TARGET=	test

post-extract:
	@${MV} ${WRKDIR}/*.c ${WRKDIR}/*.h ${WRKSRC}/plugins
	@${MKDIR} ${WRKSRC}/MoCha
	@${MV} ${WRKDIR}/*.R ${WRKSRC}/MoCha

pre-configure:
	@${REINPLACE_CMD} -e 's|@PORTVERSION@|${PORTVERSION}|g' \
		${WRKSRC}/configure.ac

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/extendFMT.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/mocha.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/mochatools.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/score.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/trio-phase.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools

.include <bsd.port.mk>
