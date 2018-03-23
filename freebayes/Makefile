# $FreeBSD$

PORTNAME=	freebayes
# FIXME: Do we need a version >= the submodules bamtools and vcflib?
# SeqLib replaces bamtools.  Bamtools was an ekg fork as well.
PORTVERSION=	1.1.0p20180214
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bayesian haplotype-based polymorphism discovery and genotyping

LICENSE=	MIT

BUILD_DEPENDS=	intervaltree>=0:wip/intervaltree \
		multichoose>=0:wip/multichoose \
		SeqLib>=0:wip/seqlib
LIB_DEPENDS=	libvcflib.so:wip/vcflib \
		libtabix.so:wip/tabixpp \
		libsw.so:wip/smithwaterman \
		libhts.so:biology/htslib

USES=		compiler:openmp gmake

USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TAGNAME=	c15b070639d54d112988946a6902d945357e40f0

CFLAGS+=	-I${LOCALBASE}/include/jsoncpp \
		-I${LOCALBASE}/include/bamtools \
		-I${LOCALBASE}/include/intervaltree \
		-I${LOCALBASE}/include/vcflib \
		-I${LOCALBASE}/include/multichoose \
		-I${LOCALBASE}/include/smithwaterman \
		-I${LOCALBASE}/include/SeqLib \
		-I${LOCALBASE}/include/SeqLib/htslib \
		-I${LOCALBASE}/include/fastahack

MAKEFILE=	Makefile.external-libs

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/bamleftalign bin/freebayes

post-patch:
	@${CP} ${FILESDIR}/Makefile.external-libs ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile.external-libs-src \
		${WRKSRC}/src/Makefile.external-libs

.include <bsd.port.mk>
