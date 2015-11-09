# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	ddocent
PORTVERSION=	2015.11.08
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
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
		vcflib>=0:/usr/wip/biology/vcflib

# Still needs:
# FreeBayes 	https://github.com/ekg/freebayes
# STACKS 	http://creskolab.uoregon.edu/stacks
# Trimmomatic 	http://www.usadellab.org/cms/?page=trimmomatic
# rainbow 	http://sourceforge.net/projects/bio-rainbow/files/
# seqtk 	https://github.com/lh3/seqtk
# bedtools 	https://code.google.com/p/bedtools/
# bamtools 	https://github.com/pezmaster31/bamtools
# PEAR read merger**

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
