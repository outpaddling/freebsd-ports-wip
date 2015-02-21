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

# Deps
# Trinity (includes TransDecoder and support for expression and DE analysis using RSEM and Bioconductor): http://trinityrnaseq.github.io/ download Trinity.
# sqlite (required for database integration): http://www.sqlite.org/
# NCBI BLAST+: Blast database Homology Search: http://www.ncbi.nlm.nih.gov/books/NBK52640/
# HMMER/PFAM Protein Domain Identification: http://hmmer.janelia.org/software

WRKSRC=		${WRKDIR}/Trinotate-${PORTVERSION}

.include <bsd.port.mk>
