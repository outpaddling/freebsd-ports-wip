# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	freebayes
# FIXME: Do we need a version >= the submodules bamtools and vcflib?
PORTVERSION=	2015.12.15
CATEGORIES=	wip biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Bayesian haplotype-based polymorphism discovery and genotyping

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/intervaltree/IntervalTree.h:wip/intervaltree \
		${LOCALBASE}/include/multichoose/multichoose.h:wip/multichoose
LIB_DEPENDS=	libbamtools.so:wip/bamtools \
		libvcflib.so:wip/vcflib \
		libtabix.so:wip/tabixpp \
		libsw.so:wip/smithwaterman \
		libhts.so:biology/htslib

USES=		compiler:c++11-lang gmake

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	65c4880d09ec21f7f2755eac9476b607011522f3

CFLAGS+=	-I${LOCALBASE}/include/bamtools \
		-I${LOCALBASE}/include/intervaltree \
		-I${LOCALBASE}/include/vcflib \
		-I${LOCALBASE}/include/multichoose \
		-I${LOCALBASE}/include/smithwaterman

MAKEFILE=	Makefile.external-libs

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/bamleftalign bin/freebayes

.include <bsd.port.mk>
