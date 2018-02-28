# $FreeBSD$

PORTNAME=	ddocent
PORTVERSION=	2.2.19
DISTVERSIONPREFIX=v
CATEGORIES=	wip biology java

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bash pipeline for ddRAD sequencing

LICENSE=	MIT

# Notes on 2015.11.30 snapshot:
# bedtools version: https://github.com/jpuritz/dDocent/issues/15
# New ddocent works with 2.23.0 or >= 2.26.0
# vcftools 0.1.14 does not report version the same as 0.1.11, so
# dDocent script fails to recognize it.  Should be easy to patch
# assuming 0.1.14 is usable.
# 0.1.15 reports version properly.
# Do we really need trimadap?  It used to be part of seqtk.
# ddocent test data do not unpack with FreeBSD 10.3 /usr/bin/unzip
RUN_DEPENDS=	unzip>=0:archivers/unzip \
		mawk>=0:lang/mawk \
		bwa>=0.7.13:wip/bwa \
		samtools>=1.3:biology/samtools \
		cd-hit>=0:biology/cd-hit \
		gnuplot>=0:math/gnuplot \
		parallel>=0:sysutils/parallel \
		gawk>=0:lang/gawk \
		vcftools>=0.1.15:wip/vcftools \
		vcflib>=0:wip/vcflib \
		rainbow>=0:wip/rainbow \
		bamtools>=0:wip/bamtools \
		freebayes:wip/freebayes \
		stacks>=0:wip/stacks \
		trimmomatic>=0:biology/trimmomatic \
		seqtk>=0:wip/seqtk \
		trimadap>=0:wip/trimadap \
		bedtools>=2.26.0:wip/bedtools \
		pear-merger>=0:wip/pear-merger

USES=		shebangfix tar:xz
USE_JAVA=	yes
SHEBANG_FILES=	dDocent scripts/*.sh scripts/*.pl scripts/dDocent_filters

USE_GITHUB=	yes
GH_ACCOUNT=	jpuritz
GH_PROJECT=	dDocent

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${GH_PROJECT}-${PORTVERSION}

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
		${WRKSRC}/scripts/*.pl \
		${WRKSRC}/scripts/dDocent_filters \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
