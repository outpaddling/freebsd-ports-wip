# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	freebayes
# FIXME: Do we need a version >= the submodules bamtools and vcflib?
PORTVERSION=	0.9.21
CATEGORIES=	biology

MAINTAINER=	jwbacon@tds.net
COMMENT=	Bayesian haplotype-based polymorphism discovery and genotyping

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/lib/libvcflib.a:/usr/wip/biology/vcflib
# LIB_DEPENDS=	libbamtools.so:/usr/wip/biology/bamtools
# ekg/intervaltree

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TAGNAME=	v${PORTVERSION}

.include <bsd.port.mk>
