PORTNAME=	bio-mocha
DISTVERSION=	1.16
CATEGORIES=	wip biology
MASTER_SITES=	https://software.broadinstitute.org/software/mocha/
DISTFILES+=	${PORTNAME}_${DISTVERSION}-20221221.tar.gz

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bcftools plugin for mosaic chromosomal alteration analysis
WWW=		https://software.broadinstitute.org/software/mocha/

LICENSE=	MIT

LIB_DEPENDS=	libhts.so:wip/htslib
BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bcftools>=${PORTVERSION}:wip/bcftools

USES=		autoreconf gmake localbase perl5 python:env shebangfix
USE_GITHUB=	yes
USE_PERL5=	test

GH_ACCOUNT=	samtools
GH_PROJECT=	bcftools
GH_TAGNAME=	1.16
GNU_CONFIGURE=	yes
SHEBANG_FILES=	misc/* test/test.pl

post-extract:
	@${MV} ${WRKDIR}/*.c ${WRKDIR}/*.h ${WRKSRC}/plugins
	@${MKDIR} ${WRKSRC}/MoCha
	@${MV} ${WRKDIR}/*.R ${WRKSRC}/MoCha

pre-configure:
	@${REINPLACE_CMD} -e 's|@PORTVERSION@|${PORTVERSION}|g' \
		${WRKSRC}/configure.ac

# One .so for each .c in the mocha distfile
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/extendFMT.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/mocha.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/mochatools.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/trio-phase.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools
	(cd ${WRKSRC}/MoCha && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
