# Created by: Bob Zimmermann <rpz@cse.wustl.edu>
# $FreeBSD: head/biology/gmap/Makefile 340722 2014-01-22 17:00:46Z mat $

PORTNAME=	gmap
PORTVERSION=	2014.07.04
CATEGORIES=	biology
MASTER_SITES=	http://research-pub.gene.com/gmap/src/
http://www.gene.com/share/gmap/src/
DISTNAME=	${PORTNAME}-${PORTVERSION:C|\.|-|g}
DISTFILES=	${PORTNAME}-gsnap-${PORTVERSION:C|\.|-|g}${EXTRACT_SUFX}

MAINTAINER=	rpz@cse.wustl.edu
COMMENT=	Genomic Mapping and Alignment Program for mRNA and EST Sequences

USES=		gmake perl5
GNU_CONFIGURE=	yes

# shebang_fix operates during patch and scripts are created during configure
post-configure:
	${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|g' \
		${WRKSRC}/Makefile ${WRKSRC}/util/*.pl

.include <bsd.port.mk>
