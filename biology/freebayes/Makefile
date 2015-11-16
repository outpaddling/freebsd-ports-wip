# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	freebayes
# FIXME: Do we need a version >= the submodules bamtools and vcflib?
PORTVERSION=	0.9.21
CATEGORIES=	biology

MAINTAINER=	jwbacon@tds.net
COMMENT=	Bayesian haplotype-based polymorphism discovery and genotyping

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/lib/libvcflib.a:/usr/wip/biology/vcflib \
		${LOCALBASE}/include/IntervalTree.h:/usr/wip/math/intervaltree
LIB_DEPENDS=	libbamtools.so:/usr/wip/biology/bamtools

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TAGNAME=	v${PORTVERSION}

CFLAGS+=	-I${LOCALBASE}/include/bamtools

post-patch:
	${REINPLACE_CMD} \
		-e 's|../intervaltree/IntervalTree.h|IntervalTree.h|g' \
		${WRKSRC}/src/BedReader.*

.include <bsd.port.mk>
