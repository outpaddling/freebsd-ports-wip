# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

# FIXME: Needs to be unbundled.  tabixpp, htslib, fastahack are all separate
# packages.  Use same strategy as py-pbfalcon: Snapshot vcflib and all
# submodules using recursive git and roll separate distfiles.

PORTNAME=	vcflib
PORTVERSION=	2015.11.08
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	C++ library and CLI tools for parsing and manipulating VCF files

USES=		compiler:openmp gmake shebangfix tar:xz
SHEBANG_FILES=	bin/vcfgtcompare.sh \
		bin/vcfmultiway \
		bin/vcfmultiwayscripts \
		bin/vcfplotaltdiscrepancy.sh \
		bin/vcfplottstv.sh \
		bin/vcfprintaltdiscrepancy.sh \
		bin/vcfregionreduce \
		bin/vcfregionreduce_and_cut \
		bin/vcfregionreduce_pipe \
		bin/vcfregionreduce_uncompressed \
		bin/vcfsort

LIB_DEPENDS=	libhts.so:${PORTSDIR}/biology/htslib
# fastahack, filevercmp, fsom, intervaltree, multichoose, smithwaterman, tabixpp

.include <bsd.port.pre.mk>

# GCC disables sse2 by default on i386, but it's required for vcflib
.if ${ARCH} == i386
CFLAGS+=	-msse2
.endif

# MAKE_JOBS_UNSAFE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|make|${GMAKE}|g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|g++|${CXX}|g' ${WRKSRC}/smithwaterman/Makefile
	${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/filevercmp/Makefile
	${REINPLACE_CMD} -e 's|defined(__APPLE__)|& \|\| defined(__FreeBSD__)|g' ${WRKSRC}/fastahack/LargeFileSupport.h
	${REINPLACE_CMD} \
		-e 's|CPP|CXX|g' \
		-e 's|main.cpp htslib/libhts.a|main.cpp|g' \
		-e 's|-Ihtslib|-I${LOCALBASE}/include|g' \
		-e 's|-Lhtslib|-L${LOCALBASE}/lib|g' \
		${WRKSRC}/tabixpp/Makefile
	${REINPLACE_CMD} \
		-e 's|^CC[ \t]*=|CC ?=|' \
		-e 's|^CXX[ \t]*=|CXX ?=|' \
		-e 's|^CFLAGS[ \t]*=|CFLAGS +=|' \
		-e 's|^CXXFLAGS[ \t]*=|CXXFLAGS +=|' \
		${WRKSRC}/Makefile \
		${WRKSRC}/*/Makefile \
		${WRKSRC}/*/*/Makefile

# FIXME: Not sure which header files need to be installed
# FIXME: Add install target to upstream Makefile
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin \
		${STAGEDIR}${PREFIX}/lib \
		${STAGEDIR}${PREFIX}/include
	${INSTALL_PROGRAM} \
		${WRKSRC}/bin/vcf2dag \
		${WRKSRC}/bin/vcf2fasta \
		${WRKSRC}/bin/vcf2tsv \
		${WRKSRC}/bin/vcfaddinfo \
		${WRKSRC}/bin/vcfafpath \
		${WRKSRC}/bin/vcfallelicprimitives \
		${WRKSRC}/bin/vcfaltcount \
		${WRKSRC}/bin/vcfannotate \
		${WRKSRC}/bin/vcfannotategenotypes \
		${WRKSRC}/bin/vcfbreakmulti \
		${WRKSRC}/bin/vcfcat \
		${WRKSRC}/bin/vcfcheck \
		${WRKSRC}/bin/vcfclassify \
		${WRKSRC}/bin/vcfcleancomplex \
		${WRKSRC}/bin/vcfcombine \
		${WRKSRC}/bin/vcfcommonsamples \
		${WRKSRC}/bin/vcfcountalleles \
		${WRKSRC}/bin/vcfcreatemulti \
		${WRKSRC}/bin/vcfdistance \
		${WRKSRC}/bin/vcfecho \
		${WRKSRC}/bin/vcfentropy \
		${WRKSRC}/bin/vcfevenregions \
		${WRKSRC}/bin/vcffilter \
		${WRKSRC}/bin/vcffixup \
		${WRKSRC}/bin/vcfflatten \
		${WRKSRC}/bin/vcfgeno2alleles \
		${WRKSRC}/bin/vcfgeno2haplo \
		${WRKSRC}/bin/vcfgenosamplenames \
		${WRKSRC}/bin/vcfgenosummarize \
		${WRKSRC}/bin/vcfgenotypecompare \
		${WRKSRC}/bin/vcfgenotypes \
		${WRKSRC}/bin/vcfglbound \
		${WRKSRC}/bin/vcfglxgt \
		${WRKSRC}/bin/vcfhetcount \
		${WRKSRC}/bin/vcfhethomratio \
		${WRKSRC}/bin/vcfindex \
		${WRKSRC}/bin/vcfinfo2qual \
		${WRKSRC}/bin/vcfinfosummarize \
		${WRKSRC}/bin/vcfintersect \
		${WRKSRC}/bin/vcfkeepgeno \
		${WRKSRC}/bin/vcfkeepinfo \
		${WRKSRC}/bin/vcfkeepsamples \
		${WRKSRC}/bin/vcfleftalign \
		${WRKSRC}/bin/vcflength \
		${WRKSRC}/bin/vcfnumalt \
		${WRKSRC}/bin/vcfoverlay \
		${WRKSRC}/bin/vcfparsealts \
		${WRKSRC}/bin/vcfprimers \
		${WRKSRC}/bin/vcfqual2info \
		${WRKSRC}/bin/vcfrandom \
		${WRKSRC}/bin/vcfrandomsample \
		${WRKSRC}/bin/vcfremap \
		${WRKSRC}/bin/vcfremoveaberrantgenotypes \
		${WRKSRC}/bin/vcfremovesamples \
		${WRKSRC}/bin/vcfroc \
		${WRKSRC}/bin/vcfsample2info \
		${WRKSRC}/bin/vcfsamplediff \
		${WRKSRC}/bin/vcfsamplenames \
		${WRKSRC}/bin/vcfsitesummarize \
		${WRKSRC}/bin/vcfstats \
		${WRKSRC}/bin/vcfstreamsort \
		${WRKSRC}/bin/vcfuniq \
		${WRKSRC}/bin/vcfuniqalleles \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/bin/bed2region \
		${WRKSRC}/bin/plot_roc.r \
		${WRKSRC}/bin/vcf2bed.py \
		${WRKSRC}/bin/vcf2sqlite.py \
		${WRKSRC}/bin/vcf_strip_extra_headers \
		${WRKSRC}/bin/vcfbiallelic \
		${WRKSRC}/bin/vcfclearid \
		${WRKSRC}/bin/vcfclearinfo \
		${WRKSRC}/bin/vcfcomplex \
		${WRKSRC}/bin/vcffirstheader \
		${WRKSRC}/bin/vcfgtcompare.sh \
		${WRKSRC}/bin/vcfindelproximity \
		${WRKSRC}/bin/vcfindels \
		${WRKSRC}/bin/vcfmultiallelic \
		${WRKSRC}/bin/vcfmultiway \
		${WRKSRC}/bin/vcfmultiwayscripts \
		${WRKSRC}/bin/vcfnobiallelicsnps \
		${WRKSRC}/bin/vcfnoindels \
		${WRKSRC}/bin/vcfnosnps \
		${WRKSRC}/bin/vcfnulldotslashdot \
		${WRKSRC}/bin/vcfplotaltdiscrepancy.r \
		${WRKSRC}/bin/vcfplotaltdiscrepancy.sh \
		${WRKSRC}/bin/vcfplotsitediscrepancy.r \
		${WRKSRC}/bin/vcfplottstv.sh \
		${WRKSRC}/bin/vcfprintaltdiscrepancy.r \
		${WRKSRC}/bin/vcfprintaltdiscrepancy.sh \
		${WRKSRC}/bin/vcfqualfilter \
		${WRKSRC}/bin/vcfregionreduce \
		${WRKSRC}/bin/vcfregionreduce_and_cut \
		${WRKSRC}/bin/vcfregionreduce_pipe \
		${WRKSRC}/bin/vcfregionreduce_uncompressed \
		${WRKSRC}/bin/vcfremovenonATGC \
		${WRKSRC}/bin/vcfsnps \
		${WRKSRC}/bin/vcfsort \
		${WRKSRC}/bin/vcfvarstats \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.post.mk>
