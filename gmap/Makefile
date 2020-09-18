# Created by: Bob Zimmermann <rpz@cse.wustl.edu>
# $FreeBSD: head/biology/gmap/Makefile 504785 2019-06-21 11:15:08Z linimon $

PORTNAME=	gmap
PORTVERSION=	2020.09.12
CATEGORIES=	wip biology
MASTER_SITES=	http://research-pub.gene.com/gmap/src/
DISTNAME=	${PORTNAME}-gsnap-${PORTVERSION:C|\.|-|g}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Genomic Mapping and Alignment Program for mRNA and EST Sequences

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	invokes x86 assembler

LICENSE=	GMAP
LICENSE_NAME=	GMAP License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		gmake perl5
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C|\.|-|g}
CFLAGS+=	-fcommon

OPTIONS_DEFINE=	SIMD

SIMD_CONFIGURE_OFF=	--disable-builtin-popcount --disable-simd

.include <bsd.port.mk>
