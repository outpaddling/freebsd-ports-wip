PORTNAME=		combine-seqlib
DISTVERSIONPREFIX=	v
DISTVERSION=		1.1.2
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C++ htslib/bwa-mem/fermi interface for interrogating sequence data
WWW=		https://github.com/COMBINE-lab/SeqLib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjsoncpp.so:devel/jsoncpp

USES=		tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	COMBINE-lab
GH_PROJECT=	SeqLib
GH_TUPLE=	samtools:htslib:be22a2a:hts/htslib

GNU_CONFIGURE=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/SeqLib/htslib/htslib
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/SeqLib/htslib/cram
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/SeqLib/bwa
	${INSTALL_DATA} \
		${WRKSRC}/SeqLib/*.h \
		${WRKSRC}/SeqLib/*.hpp \
		${WRKSRC}/SeqLib/GenomicRegionCollection.cpp \
		${STAGEDIR}${PREFIX}/include/SeqLib
	${INSTALL_DATA} ${WRKSRC}/htslib/cram/*.h \
		${STAGEDIR}${PREFIX}/include/SeqLib/htslib/cram
	${INSTALL_DATA} ${WRKSRC}/htslib/htslib/*.h \
		${STAGEDIR}${PREFIX}/include/SeqLib/htslib/htslib
	${INSTALL_DATA} ${WRKSRC}/bwa/*.h \
		${STAGEDIR}${PREFIX}/include/SeqLib/bwa
	${INSTALL_DATA} ${WRKSRC}/src/libseqlib.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
