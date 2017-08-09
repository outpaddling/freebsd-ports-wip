# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	ddocent
PORTVERSION=	2015.11.30
CATEGORIES=	wip biology java
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Bash pipeline for ddRAD sequencing

LICENSE=	MIT

# Notes on 2015.11.30 snapshot:
# bedtools version: https://github.com/jpuritz/dDocent/issues/15
# Do we really still need bedtools 2.23.0?
# vcftools 0.1.14 does not report version the same as 0.1.11, so
# dDocent script fails to recognize it.  Should be easy to patch
# assuming 0.1.14 is usable.
RUN_DEPENDS=	mawk>=0:lang/mawk \
		bwa>=0:biology/bwa \
		samtools01>=0:wip/samtools0119 \
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
		bedtools2==2.23.0:wip/bedtools2 \
		pear-merger>=0:wip/pear

USES=		shebangfix tar:xz
USE_JAVA=	yes
SHEBANG_FILES=	dDocent scripts/*

NO_BUILD=	yes

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
		${WRKSRC}/scripts/* ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
