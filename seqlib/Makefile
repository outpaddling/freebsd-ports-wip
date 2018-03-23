# $FreeBSD$

PORTNAME=	SeqLib
PORTVERSION=	1.1.2p20171021
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C++ htslib/bwa-mem/fermi interface for interrogating sequence data

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	fermi-lite-walaj>=0:wip/fermi-lite-walaj

USE_GITHUB=	yes
GH_ACCOUNT=	walaj
GH_TAGNAME=	62857243562cf1e4cd89f74f0cbd4c14b0a64e37

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include

post-patch:
	${REINPLACE_CMD} -e 's|htslib/htslib/|htslib/|g' \
		${WRKSRC}/SeqLib/*.h \
		${WRKSRC}/benchmark/benchmark.cpp \
		${WRKSRC}/src/ReadFilter.cpp

.include <bsd.port.mk>
