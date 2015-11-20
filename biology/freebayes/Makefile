# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	freebayes
# FIXME: Do we need a version >= the submodules bamtools and vcflib?
PORTVERSION=	0.9.21
CATEGORIES=	biology

MAINTAINER=	jwbacon@tds.net
COMMENT=	Bayesian haplotype-based polymorphism discovery and genotyping

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/intervaltree/IntervalTree.h:/usr/wip/math/intervaltree
LIB_DEPENDS=	libbamtools.so:/usr/wip/biology/bamtools \
		libvcflib.so:/usr/wip/biology/vcflib

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TAGNAME=	v${PORTVERSION}

CFLAGS+=	-I${LOCALBASE}/include/bamtools \
		-I${LOCALBASE}/include/intervaltree \
		-I${LOCALBASE}/include/vcflib \
		-I${LOCALBASE}/include/multichoose \
		-I${LOCALBASE}/include/smithwaterman

MAKE_JOBS_UNSAFE=	yes

post-patch:
	${REINPLACE_CMD} \
		-e 's|../intervaltree/IntervalTree.h|IntervalTree.h|g' \
		${WRKSRC}/src/BedReader.*

.include <bsd.port.mk>
