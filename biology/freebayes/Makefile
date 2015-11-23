# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	freebayes
# FIXME: Do we need a version >= the submodules bamtools and vcflib?
PORTVERSION=	bf31341be12fa616fe1e43c8aef7a04108f7bfdc
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Bayesian haplotype-based polymorphism discovery and genotyping

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/intervaltree/IntervalTree.h:/usr/wip/math/intervaltree \
		${LOCALBASE}/include/multichoose/multichoose.h:/usr/wip/math/multichoose
LIB_DEPENDS=	libbamtools.so:/usr/wip/biology/bamtools \
		libvcflib.so.1:/usr/wip/biology/vcflib \
		libtabix.so.1:/usr/wip/biology/tabixpp \
		libsw.so.1:/usr/wip/biology/smithwaterman \
		libhts.so:/usr/ports/biology/htslib

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

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/bamleftalign bin/freebayes

.include <bsd.port.mk>
