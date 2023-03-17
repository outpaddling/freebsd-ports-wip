PORTNAME=	omics
PORTVERSION=	1.1.3
CATEGORIES=	wip biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-pipe
DISTNAME=	omics_pipe-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Multi-omics data analysis pipelines
WWW=		https://pypi.python.org/pypi/omics-pipe

LICENSE=	MIT

# Do not add gatk as a dep.  It is restricted and will prevent packaging.
RUN_DEPENDS=	samtools>=0:biology/samtools \
		fastqc>=0:wip/fastqc \
		tophat>=0:wip/tophat \
		cufflinks>=0:wip/cufflinks \
		bwa>=0:biology/bwa \
		picard-tools>=0:wip/picard-tools \
		bedtools>=0:biology/bedtools \
		bowtie>=0:biology/bowtie \
		mercurial>=0:devel/mercurial \
		${PYTHON_PKGNAMEPREFIX}raven>0:devel/py-raven \
		${PYTHON_PKGNAMEPREFIX}hgapi>0:wip/py-hgapi \
		${PYTHON_PKGNAMEPREFIX}argparse>0:devel/py-argparse \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}sumatra>0:wip/py-sumatra \
		${PYTHON_PKGNAMEPREFIX}drmaa>0:wip/py-drmaa \
		${PYTHON_PKGNAMEPREFIX}ruffus>0:wip/py-ruffus \

# R Packages Needed
# In R, you can cut and copy this to install all required packages:
# install.packages(c("bibtex",    "AnnotationDbi", "cluster", "cummeRbund", "data.table", "DBI", "DESeq2", "devtools",    "dplyr",        "gdata",
# "ggplot2", "graphite", "igraph", "KEGGREST","knitr", "knitrBootstrap",  "lattice", "locfit",    "pamr", "pander",       "pathview",
# "plyr","RColorBrewer","Rcpp",   "RcppArmadillo", "RCurl", "ReactomePA", "RefManageR","RJSONIO","RSQLite",
# "stringr","survival", "XML", "xtable",  "yaml"))
# RNA-seq (Tuxedo)
#    FASTQC: 	http://www.bioinformatics.babraham.ac.uk/projects/fastqc/
#    TOPHAT: 	http://tophat.cbcb.umd.edu/
#    CUFFLINKS: 	http://cufflinks.cbcb.umd.edu/
# RNA-seq (Anders 2013)
#    FASTQC: 	http://www.bioinformatics.babraham.ac.uk/projects/fastqc/
#    STAR: 	http://code.google.com/p/rna-star/
#    SAMTOOLS: 	http://samtools.sourceforge.net/
#    HTSEQ: 	http://www-huber.embl.de/users/anders/HTSeq/doc/index.html
# Whole Exome Sequencing (GATK)
#    FASTQC: 	http://www.bioinformatics.babraham.ac.uk/projects/fastqc/
#    BWA: 	http://bio-bwa.sourceforge.net/
#    PICARD: 	http://picard.sourceforge.net/
#    GATK: 	https://www.broadinstitute.org/gatk/download
# Whole Genome Sequencing (GATK)
#    FASTQC: 	http://www.bioinformatics.babraham.ac.uk/projects/fastqc/
#    BWA: 	http://bio-bwa.sourceforge.net/
#    PICARD: 	http://picard.sourceforge.net/
#    GATK: 	https://www.broadinstitute.org/gatk/download
# Whole Genome Sequencing (MUTECT)
#    FASTQC: 	http://www.bioinformatics.babraham.ac.uk/projects/fastqc/
#    BWA: 	http://bio-bwa.sourceforge.net/
#    MUTECT: 	http://www.broadinstitute.org/cancer/cga/mutect
# ChIP-seq (MACS)
#    FASTQC: 	http://www.bioinformatics.babraham.ac.uk/projects/fastqc/
#    HOMER: 	http://homer.salk.edu/homer/ngs/index.html
#    BOWTIE: 	http://bowtie-bio.sourceforge.net/index.shtml
#    MACS: 	http://liulab.dfci.harvard.edu/MACS/
#    BEDTOOLS: 	https://github.com/arq5x/bedtools2
#    SAMTOOLS: 	http://samtools.sourceforge.net/
# ChIP-seq (HOMER)
#    FASTQC: 	http://www.bioinformatics.babraham.ac.uk/projects/fastqc/
#    HOMER: 	http://homer.salk.edu/homer/ngs/index.html
#    BOWTIE: 	http://bowtie-bio.sourceforge.net/index.shtml
#    BEDTOOLS: 	https://github.com/arq5x/bedtools2
# Breast Cancer Personalized Genomics Report- RNAseq
#    FASTQC: 	http://www.bioinformatics.babraham.ac.uk/projects/fastqc/
#    STAR: 	http://code.google.com/p/rna-star/
#    SAMTOOLS: 	http://samtools.sourceforge.net/
#    HTSEQ: 	http://www-huber.embl.de/users/anders/HTSeq/doc/index.html
#    RSEQC: 	http://rseqc.sourceforge.net/
#    PICARD: 	http://picard.sourceforge.net/
#    GATK: 	https://www.broadinstitute.org/gatk/download
#    FusionCatcher: 	https://code.google.com/p/fusioncatcher/
#    Oncofuse: 	http://www.unav.es/genetica/oncofuse.html
#    BWA: 	http://bio-bwa.sourceforge.net/
#    DNANEXUS SAMTOOLS: 	https://github.com/dnanexus/samtools
#    BEDTOOLS: 	https://github.com/arq5x/bedtools2
#    BLAT: 	https://genome.ucsc.edu/FAQ/FAQblat.html#blat3
#    SNPiR: 	http://lilab.stanford.edu/SNPiR/
#    SNPEFF: 	http://snpeff.sourceforge.net/
#    SNPSIFT: 	http://snpeff.sourceforge.net/SnpSift.html
#    VCFTOOLS: 	http://vcftools.sourceforge.net/
# TCGA Reanalysis Pipeline - RNAseq
#    GeneTorrent: 	https://cghub.ucsc.edu/docs/user/software.html
#    FASTQC: 	http://www.bioinformatics.babraham.ac.uk/projects/fastqc/
#    STAR: 	http://code.google.com/p/rna-star/
#    SAMTOOLS: 	http://samtools.sourceforge.net/
#    HTSEQ: 	http://www-huber.embl.de/users/anders/HTSeq/doc/index.html
#    RSEQC: 	http://rseqc.sourceforge.net/
#    PICARD: 	http://picard.sourceforge.net/
#    GATK: 	https://www.broadinstitute.org/gatk/download
#    FusionCatcher: 	https://code.google.com/p/fusioncatcher/
#    Oncofuse: 	http://www.unav.es/genetica/oncofuse.html
#    BWA: 	http://bio-bwa.sourceforge.net/
#    DNANEXUS SAMTOOLS: 	https://github.com/dnanexus/samtools
#    BEDTOOLS: 	https://github.com/arq5x/bedtools2
#    BLAT: 	https://genome.ucsc.edu/FAQ/FAQblat.html#blat3
#    SNPiR: 	http://lilab.stanford.edu/SNPiR/
#    SNPEFF: 	http://snpeff.sourceforge.net/
#    SNPSIFT: 	http://snpeff.sourceforge.net/SnpSift.html
#    VCFTOOLS: 	http://vcftools.sourceforge.net/
# TCGA Reanalysis Pipeline - RNAseq Counts
#    GeneTorrent: 	https://cghub.ucsc.edu/docs/user/software.html
#    FASTQC: 	http://www.bioinformatics.babraham.ac.uk/projects/fastqc/
#    STAR: 	http://code.google.com/p/rna-star/
#    SAMTOOLS: 	http://samtools.sourceforge.net/
#    HTSEQ: 	http://www-huber.embl.de/users/anders/HTSeq/doc/index.html
# miRNAseq Counts (Anders 2013)
#    CutAdapt: 	http://code.google.com/p/cutadapt/
#    FASTQC: 	http://www.bioinformatics.babraham.ac.uk/projects/fastqc/
#    STAR: 	http://code.google.com/p/rna-star/
#    SAMTOOLS: 	http://samtools.sourceforge.net/
#    HTSEQ: 	http://www-huber.embl.de/users/anders/HTSeq/doc/index.html
# miRNAseq (Tuxedo)
#    CutAdapt: 	http://code.google.com/p/cutadapt/
#    FASTQC: 	http://www.bioinformatics.babraham.ac.uk/projects/fastqc/
#    TOPHAT: 	http://tophat.cbcb.umd.edu/
#    CUFFLINKS: 	http://cufflinks.cbcb.umd.edu/

USES=		python:3.6+
USE_PYTHON=	distutils

.include <bsd.port.mk>
