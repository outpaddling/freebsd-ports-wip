# Created by: Bob Zimmermann <rpz@cse.wustl.edu>
# $FreeBSD: head/biology/gmap/Makefile 340722 2014-01-22 17:00:46Z mat $

PORTNAME=	gmap
PORTVERSION=	2015.09.21
CATEGORIES=	biology
MASTER_SITES=	http://research-pub.gene.com/gmap/src/
DISTNAME=	${PORTNAME}-gsnap-${PORTVERSION:C|\.|-|g}

MAINTAINER=	rpz@cse.wustl.edu
COMMENT=	Genomic Mapping and Alignment Program for mRNA and EST Sequences

# LICENSE=	
# LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake perl5
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C|\.|-|g}

# shebang_fix operates during patch.
# These scripts are created during configure.
post-configure:
	${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|g' \
		${WRKSRC}/Makefile ${WRKSRC}/util/*.pl

.include <bsd.port.mk>
