PORTNAME=	biostar-tools
PORTVERSION=	1
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Meta-port for Biostar Handbook tools

# bedgraphtobigwig is part of ucsc-kentutils
# For a current list see http://data.biostarhandbook.com/install/conda.txt.
RUN_DEPENDS=	wget>0:ftp/wget \
		nano>0:editors/nano \
		parallel>0:sysutils/parallel \
		seqkit>0:biology/seqkit \
		edirect>0:wip/edirect \
		ucsc-kentutils>0:wip/ucsc-kentutils \
		readseq>0:wip/readseq \
		snpeff>0:wip/snpeff \
		picard-tools>0:biology/picard-tools \
		bbmap>0:wip/bbmap \
		minimap2>0:biology/minimap2 \
		bwa>=0:biology/bwa \
		bowtie2>=0:biology/bowtie2 \
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
		${PYTHON_PKGNAMEPREFIX}crossmap>0:biology/py-crossmap@${PY_FLAVOR}

USES=		metaport python

.include <bsd.port.mk>
