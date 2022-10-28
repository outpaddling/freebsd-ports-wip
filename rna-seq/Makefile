PORTNAME=	rna-seq
DISTVERSION=	0.1.0
CATEGORIES=	wip biology python
MASTER_SITES=	# empty

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Metaport for RNA-Seq analysis
WWW=		https://example.com/rna-seq

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	fastqc>0:biology/fastqc \
		${PYTHON_PKGNAMEPREFIX}multiqc>0:biology/py-multiqc@${PY_FLAVOR} \
		fastq-trim>0:biology/fastq-trim \
		biolibc-tools>0:biology/biolibc-tools \
		gffread>0:biology/gffread \
		kallisto>0:biology/kallisto \
		bwa>0:biology/bwa \
		bowtie2>0:biology/bowtie2 \
		hisat2>0:biology/hisat2 \
		igv>0:biology/igv \
		samtools>0:biology/samtools \
		fasda>0:wip/fasda

USES=		metaport python

.include <bsd.port.mk>
