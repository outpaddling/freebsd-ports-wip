# $FreeBSD$

PORTNAME=	dDocent
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.25
CATEGORIES=	wip biology java

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Bash pipeline for RAD sequencing

LICENSE=	MIT

# Notes on 2015.11.30 snapshot:
# bedtools version: https://github.com/jpuritz/dDocent/issues/15
# New ddocent works with 2.23.0 or >= 2.26.0
# vcftools 0.1.14 does not report version the same as 0.1.11, so
# dDocent script fails to recognize it.  Should be easy to patch
# assuming 0.1.14 is usable.
# 0.1.15 reports version properly.
# Do we really need trimadap?  It used to be part of seqtk.
# ddocent test data do not unpack with FreeBSD 11.1 /usr/bin/unzip
RUN_DEPENDS=	unzip>=0:archivers/unzip \
		mawk>=0:lang/mawk \
		gawk>=0:lang/gawk \
		coreutils>=0:sysutils/coreutils \
		gnuplot>=0:math/gnuplot \
		parallel>=0:sysutils/parallel \
		bash:shells/bash \
		bwa>=0.7.13:biology/bwa \
		cd-hit>=0:biology/cd-hit \
		samtools>=1.3:biology/samtools \
		vcftools>=0.1.15:biology/vcftools \
		trimmomatic>=0:biology/trimmomatic \
		bamtools>=0:biology/bamtools \
		stacks>=0:biology/stacks \
		rainbow>=0:biology/rainbow \
		trimadap>=0:biology/trimadap \
		seqtk>=0:biology/seqtk \
		bedtools>=2.26.0:wip/bedtools \
		pear-merger>=0:biology/pear-merger \
		vcflib>=0:biology/vcflib \
		freebayes:wip/freebayes

USES=		perl5 python shebangfix
USE_JAVA=	yes
SHEBANG_FILES=	dDocent scripts/*.sh scripts/*.pl scripts/dDocent_filters

USE_GITHUB=	yes
GH_ACCOUNT=	jpuritz

NO_BUILD=	yes

# These follow patch-dDocent, so don't apply them within the source tree,
# or they'll get picked up by patch generators and hard-code PREFIX
post-stage:
	${REINPLACE_CMD} -i '' \
		-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g' \
		-e 's|python|${PYTHON_CMD}|g' \
		${STAGEDIR}${PREFIX}/bin/dDocent

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/dDocent \
		${WRKSRC}/*.sh \
		${FILESDIR}/ddocent-test \
		${FILESDIR}/ddocent-test-cleanup \
		${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/*.pl \
		${WRKSRC}/scripts/dDocent_filters \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
