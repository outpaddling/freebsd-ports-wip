# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	trinotate
PORTVERSION=	2.0.1
CATEGORIES=	biology
MASTER_SITES=	https://github.com/Trinotate/Trinotate/archive/
DISTNAME=	v2.0.1

MAINTAINER=	jwbacon@tds.net

COMMENT=	Trinotate is a comprehensive annotation suite designed for automatic functional annotation of transcriptomes, particularly de novo assembled transcriptomes, from model or non-model organisms.

LICENSE=	BSD3CLAUSE

USE_SQLITE=	yes
USES=		dos2unix shebangfix
SHEBANG_FILES=	util/*.txt
DOS2UNIX_FILES=	util/*.txt

# FIXME: Make sample_data/runMe.sh work out of the box

# Trinity must include TransDecoder and support for expression and DE analysis using RSEM and Bioconductor
RUN_DEPENDS=	trinityrnaseq>=2.0.4:/usr/wip/biology/trinity \
		ncbi-blast+>=2.2.30:${PORTSDIR}/biology/ncbi-blast+ \
		hmmer>=3.0:${PORTSDIR}/biology/hmmer

# Optional but recommended deps:
# signalP v4 http://www.cbs.dtu.dk/cgi-bin/nph-sw_request?signalp
# tmhmm v2 http://www.cbs.dtu.dk/cgi-bin/nph-sw_request?tmhmm
# rnammer http://www.cbs.dtu.dk/cgi-bin/sw_request?rnammer

# Requires sequence databases
# SwissProt ftp://ftp.broadinstitute.org/pub/Trinity/Trinotate_v2.0_RESOURCES/uniprot_sprot.trinotate_v2.0.pep.gz
# mv uniprot_sprot.trinotate_v2.0.pep.gz uniprot_sprot.trinotate.pep.gz
# gunzip uniprot_sprot.trinotate.pep.gz
# makeblastdb -in uniprot_sprot.trinotate.pep -dbtype prot

# Uniref90 ftp://ftp.broadinstitute.org/pub/Trinity/Trinotate_v2.0_RESOURCES/uniprot_uniref90.trinotate_v2.0.pep.gz
# mv uniprot_uniref90.trinotate_v2.0.pep.gz uniprot_uniref90.trinotate.pep.gz
# gunzip uniprot_uniref90.trinotate.pep.gz
# makeblastdb -in uniprot_uniref90.trinotate.pep -dbtype prot

# Pfam domains ftp://ftp.broadinstitute.org/pub/Trinity/Trinotate_v2.0_RESOURCES/Pfam-A.hmm.gz
# gunzip Pfam-A.hmm.gz
# hmmpress Pfam-A.hmm

# Boilerplate Trinotate sqlite db
# wget "ftp://ftp.broadinstitute.org/pub/Trinity/Trinotate_v2.0_RESOURCES/Trinotate.sprot_uniref90.20150131.boilerplate.sqlite.gz" -O Trinotate.sqlite.gz

WRKSRC=		${WRKDIR}/Trinotate-${PORTVERSION}

NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} \
		-e 's|$$FindBin::Bin/util|${PREFIX}/libexec/trinotate/util|g' \
		${WRKSRC}/Trinotate

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/trinotate/util
	${INSTALL_SCRIPT} ${WRKSRC}/Trinotate ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/util && \
		${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/libexec/trinotate/util)

.include <bsd.port.mk>
