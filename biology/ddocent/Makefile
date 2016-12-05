# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	ddocent
PORTVERSION=	2015.11.30
CATEGORIES=	biology java
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Bash pipeline for ddRAD sequencing

LICENSE=	MIT

# bedtools version: https://github.com/jpuritz/dDocent/issues/15
RUN_DEPENDS=	mawk>=0:lang/mawk \
		bwa>=0:/usr/wip/biology/bwa \
		samtools>=1.3:biology/samtools \
		cd-hit>=0:biology/cd-hit \
		gnuplot>=0:math/gnuplot \
		parallel>=0:sysutils/parallel \
		gawk>=0:lang/gawk \
		vcftools>=0.1.11:biology/vcftools \
		vcflib>=0:/usr/wip/biology/vcflib \
		rainbow>=0:/usr/wip/biology/rainbow \
		bamtools>=0:/usr/wip/biology/bamtools \
		freebayes:/usr/wip/biology/freebayes \
		stacks>=0:/usr/wip/biology/stacks \
		trimmomatic>=0:/usr/wip/biology/trimmomatic \
		seqtk>=0:/usr/wip/biology/seqtk \
		bedtools2==2.23.0:/usr/wip/biology/bedtools2 \
		pear-merger>=0:/usr/wip/biology/pear

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
