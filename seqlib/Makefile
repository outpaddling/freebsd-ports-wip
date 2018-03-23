# $FreeBSD$

PORTNAME=	SeqLib
PORTVERSION=	2018.03.23
CATEGORIES=	wip biology
MASTER_SITES=	https://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C++ htslib/bwa-mem/fermi interface for interrogating sequence data

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjsoncpp.so:devel/jsoncpp

USES=		gmake tar:xz
USE_GCC=	yes

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
