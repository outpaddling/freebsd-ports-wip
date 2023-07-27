PORTNAME=	rna-seq
DISTVERSION=	0.1.3
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
		kallisto>0:biology/kallisto \
		hisat2>0:biology/hisat2 \
		samtools>0:biology/samtools \
		picard-tools>0:biology/picard-tools \
		bedtools>0:biology/bedtools \
		${PYTHON_PKGNAMEPREFIX}HTSeq>0:wip/py-htseq@${PY_FLAVOR} \
		fasda>0:biology/fasda \
		webbrowser>0:www/webbrowser \
		curl>0:ftp/curl

USES=		metaport python

.include <bsd.port.mk>
