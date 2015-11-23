# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	freebayes
# FIXME: Do we need a version >= the submodules bamtools and vcflib?
PORTVERSION=	fab0673548867340a901ec62e38c8bd28cab062e
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Bayesian haplotype-based polymorphism discovery and genotyping

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/intervaltree/IntervalTree.h:/usr/wip/math/intervaltree
LIB_DEPENDS=	libbamtools.so:/usr/wip/biology/bamtools \
		libvcflib.so:/usr/wip/biology/vcflib

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	${PORTVERSION}

CFLAGS+=	-I${LOCALBASE}/include/bamtools \
		-I${LOCALBASE}/include/intervaltree \
		-I${LOCALBASE}/include/vcflib \
		-I${LOCALBASE}/include/multichoose \
		-I${LOCALBASE}/include/smithwaterman

MAKEFILE=	Makefile.external-libs
# MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
