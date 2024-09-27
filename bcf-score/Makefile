PORTNAME=	bcf-score
DISTVERSION=	1.21
CATEGORIES=	wip biology
MASTER_SITES=	https://software.broadinstitute.org/software/score/
DISTFILES+=	score_${DISTVERSION}-20221221.tar.gz

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bcftools plugins for GWAS-VCF summary statistics files
WWW=		https://software.broadinstitute.org/software/score/

LICENSE=	MIT

LIB_DEPENDS=	libhts.so:wip/htslib
BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bcftools>=${PORTVERSION}:wip/bcftools

USES=		autoreconf gmake localbase perl5 python:env shebangfix
USE_GITHUB=	yes
USE_PERL5=	test

GH_ACCOUNT=	samtools
GH_PROJECT=	bcftools
GH_TAGNAME=	1.21
GNU_CONFIGURE=	yes
SHEBANG_FILES=	misc/* test/test.pl

pre-configure:
	@${REINPLACE_CMD} -e 's|@PORTVERSION@|${PORTVERSION}|g' \
		${WRKSRC}/configure.ac

# One .so for each .c in the score distfile
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/*.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools

.include <bsd.port.mk>
