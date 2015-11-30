# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	ddocent
PORTVERSION=	2015.11.08
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Bash pipeline for ddRAD sequencing

LICENSE=	MIT

RUN_DEPENDS=	mawk>=0:${PORTSDIR}/lang/mawk \
		bwa>=0:${PORTSDIR}/biology/bwa \
		samtools>=0:${PORTSDIR}/biology/samtools \
		cd-hit>=0:${PORTSDIR}/biology/cd-hit \
		gnuplot>=0:${PORTSDIR}/math/gnuplot \
		parallel>=0:${PORTSDIR}/sysutils/parallel \
		gawk>=0:${PORTSDIR}/lang/gawk \
		vcftools>=0:/usr/wip/biology/vcftools \
		vcflib>=0:/usr/wip/biology/vcflib \
		rainbow>=0:/usr/wip/biology/rainbow \
		bamtools>=0:/usr/wip/biology/bamtools \
		freebayes:/usr/wip/biology/freebayes \
		stacks>=0:/usr/wip/biology/stacks \
		Trimmomatic>=0:/usr/wip/biology/trimmomatic \
		seqtk>=0:/usr/wip/biology/seqtk \
		bedtools2>=0:/usr/wip/biology/bedtools2 \
		pear-merger>=0:/usr/wip/biology/pear

USES=		shebangfix tar:xz
USE_JAVA=	yes
SHEBANG_FILES=	dDocent scripts/*

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/dDocent \
		${WRKSRC}/scripts/* ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
