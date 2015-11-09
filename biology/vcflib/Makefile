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

#USE_GITHUB=	yes
#GH_ACCOUNT=	ekg
#GH_TAGNAME=	v${PORTVERSION}-rc0

USES=		compiler:openmp gmake tar:xz

MAKE_JOBS_UNSAFE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|make|${GMAKE}|g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|CPP|CXX|g' ${WRKSRC}/tabixpp/Makefile
	${REINPLACE_CMD} -e 's|g++|${CXX}|g' ${WRKSRC}/smithwaterman/Makefile
	${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/filevercmp/Makefile
	${REINPLACE_CMD} -e 's|defined(__APPLE__)|defined(__APPLE__) \|\| defined(__FreeBSD__)|g' ${WRKSRC}/fastahack/LargeFileSupport.h
	${REINPLACE_CMD} \
		-e 's|^CC.*=|CC ?=|' \
		-e 's|CXX.*=|CXX ?=|' \
		${WRKSRC}/Makefile \
		${WRKSRC}/*/Makefile \
		${WRKSRC}/*/*/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin \
		${STAGEDIR}${PREFIX}/lib \
		${STAGEDIR}${PREFIX}/include
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
