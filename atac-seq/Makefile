PORTNAME=	atac-seq
DISTVERSION=	0.1.0
CATEGORIES=	wip biology python
MASTER_SITES=	# empty

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Metaport for RNA-Seq analysis
WWW=		https://github.com/auerlab/

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	sra-tools>0:biology/sra-tools \
		fastq-trim>0:biology/fastq-trim \
		fastqc>0:biology/fastqc \
		${PYTHON_PKGNAMEPREFIX}multiqc>0:biology/py-multiqc@${PY_FLAVOR} \
		biolibc-tools>0:biology/biolibc-tools \
		gffread>0:biology/gffread \
		bwa>0:biology/bwa \
		bowtie2>0:biology/bowtie \
		samtools>0:biology/samtools \
		igv>0:biology/igv \
		${PYTHON_PKGNAMEPREFIX}macs2>0:biology/py-macs2@${PY_FLAVOR} \
		peak-classifier>0:biology/peak-classifier \
		fasda>0:biology/fasda

USES=		metaport python

.include <bsd.port.mk>
