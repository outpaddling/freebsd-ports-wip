# $FreeBSD$

PORTNAME=	biostar-tools
DISTVERSION=	0.1
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Meta-port for Biostar Handbook tools

RUN_DEPENDS=	wget>0:ftp/wget \
		parallel>0:sysutils/parallel \
		edirect>0:wip/edirect \
		minimap2>0:biology/minimap2 \
		bwa>=0:biology/bwa \
		samtools>0:biology/samtools \
		emboss>0:biology/emboss \
		bedtools>0:biology/bedtools \
		bamtools>0:biology/bamtools \
		sra-tools>0:wip/sra-tools \
		${PYTHON_PKGNAMEPREFIX}cutadapt>0:biology/py-cutadapt@${PY_FLAVOR} \
		seqtk>0:biology/seqtk \
		datamash>0:textproc/datamash \
		bcftools>0:biology/bcftools \
		subread>0:wip/subread \
		hisat2>0:biology/hisat2 \
		trimmomatic>0:biology/trimmomatic \
		fastqc>0:biology/fastqc \
		picard-tools>0:wip/picard-tools \
		ncbi-blast+>0:biology/ncbi-blast+ \
		cd-hit>0:biology/cd-hit \
		${PYTHON_PKGNAMEPREFIX}biopython>0:biology/py-biopython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysam>0:biology/py-pysam@${PY_FLAVOR} \
		freebayes>0:biology/freebayes \
		seqkit>0:wip/seqkit \
		p5-Net-SSLeay>0:security/p5-Net-SSLeay \
		bioawk>0:wip/bioawk

USES=		metaport perl5 python

#bbmap
#snpeff
#vt
#readseq
#ucsc-bedgraphtobigwig

.include <bsd.port.mk>
