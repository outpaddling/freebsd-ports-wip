# $FreeBSD$

PORTNAME=	dDocent
PORTVERSION=	2.2.16
DISTVERSIONPREFIX=	v
CATEGORIES=	biology java

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Bash pipeline for RAD sequencing

LICENSE=	MIT

RUN_DEPENDS=    mawk>=0:lang/mawk \
		bwa>=0:biology/bwa \
		samtools>=0:biology/samtools \
		cd-hit>=0:biology/cd-hit \
		gnuplot>=0:math/gnuplot \
		parallel>=0:sysutils/parallel \
		gawk>=0:lang/gawk \
		vcftools>=0.1.11:biology/vcftools \
		vcflib>=0:wip/vcflib \
		rainbow>=0:wip/rainbow \
		bamtools>=0:wip/bamtools \
		freebayes:wip/freebayes \
		stacks>=0:wip/stacks \
		trimmomatic>=0:biology/trimmomatic \
		seqtk>=0:wip/seqtk \
		bedtools>=2.26.0:wip/bedtools \
		pear-merger>=0:wip/pear

USES=		shebangfix tar:xz
USE_JAVA=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	jpuritz

SHEBANG_FILES=  dDocent scripts/*

NO_BUILD=       yes

# These follow patch-dDocent, so don't apply them within the source tree,
# or they'll get picked up by patch generators and hard-code PREFIX
post-stage:
	${REINPLACE_CMD} -i '' \
		-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g' \
		${STAGEDIR}${PREFIX}/bin/dDocent
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/dDocent \
		${FILESDIR}/ddocent-test \
		${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/dDocent_filters \
		${WRKSRC}/scripts/*.pl  ${STAGEDIR}${PREFIX}/bin
.include <bsd.port.mk>
