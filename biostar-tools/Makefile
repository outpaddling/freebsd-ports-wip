# $FreeBSD$

PORTNAME=	biostar-tools
DISTVERSION=	0.1
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Meta-port for Biostar Handbook tools

# Deps from http://data.biostarhandbook.com/install/conda.txt:
# bbmap
# snpeff
# readseq
# ucsc-bedgraphtobigwig
# Other tools mentioned:
RUN_DEPENDS=	wget>0:ftp/wget \
		nano>0:editors/nano \
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
		subread>0:biology/subread \
		hisat2>0:biology/hisat2 \
		trimmomatic>0:biology/trimmomatic \
		fastqc>0:biology/fastqc \
		picard-tools>0:biology/picard-tools \
		ncbi-blast+>0:biology/ncbi-blast+ \
		cd-hit>0:biology/cd-hit \
		${PYTHON_PKGNAMEPREFIX}biopython>0:biology/py-biopython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysam>0:biology/py-pysam@${PY_FLAVOR} \
		freebayes>0:biology/freebayes \
		p5-Net-SSLeay>0:security/p5-Net-SSLeay \
		bioawk>0:biology/bioawk \
		vt>0:biology/vt \
		${PYTHON_PKGNAMEPREFIX}crossmap>0:wip/py-crossmap@${PY_FLAVOR}

# Broken		seqkit>0:wip/seqkit \

USES=		metaport python

.include <bsd.port.mk>
