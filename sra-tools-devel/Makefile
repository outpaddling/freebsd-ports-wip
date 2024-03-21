PORTNAME=	sra-tools
DISTVERSION=	3.0.10-133
DISTVERSIONSUFFIX=      -g2a26be56
CATEGORIES=	wip biology java

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	NCBI's toolkit for handling data in INSDC Sequence Read Archives
WWW=		https://github.com/ncbi/sra-tools

LICENSE=		PD LGPL21+
LICENSE_COMB=		multi
LICENSE_FILE_PD=	${WRKSRC}/LICENSE
LICENSE_DISTFILES_LGPL21+ =

# Untested on other platforms, aarch64 support was recently added upstream
ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	Upstream explicitly supports specific platforms

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libhdf5.so:science/hdf5 \
		libepoll-shim.so:devel/libepoll-shim \
		libzstd.so:archivers/zstd

USES=		bison cmake shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	${PREFIX}/lib64
USE_JAVA=	yes

# Builds with earlier versions, but ngs-doc plist differs if jdk17 is present
JAVA_VERSION=	17+

OPTIONS_DEFINE=	EXAMPLES

SHEBANG_GLOB=	*.sh
GH_ACCOUNT=	ncbi
# FIXME: Switch to ncbi engineering branch
GH_TUPLE+=	outpaddling:ncbi-vdb:802ae6e:vdb/ncbi-vdb

WITH_DEBUG=	yes
CMAKE_ARGS+=	-DVDB_LIBDIR:STRING=${WRKSRC}/ncbi-vdb/build/lib

pre-configure:
	# The config.c and file-path.posix.cpp reinplaces follow
	# static patches.  Run "make clean patch" before updating
	# those patches so this reinplace does not get added to them.
	@${REINPLACE_CMD} -e 's|"/etc/ncbi"|"${PREFIX}/etc/ncbi"|g' \
		${WRKSRC}/ncbi-vdb/libs/kfg/config.c
	@${REINPLACE_CMD} -e 's|/usr/local/bin|${PREFIX}/bin|g' \
		${WRKSRC}/tools/external/driver-tool/file-path.posix.cpp
	@${REINPLACE_CMD} -e 's|/../ncbi-vdb|/ncbi-vdb|g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/build/env.cmake \
		${WRKSRC}/ncbi-vdb/build/env.cmake \
		${WRKSRC}/ncbi-vdb/libs/kfg/CMakeLists.txt \
		${WRKSRC}/tools/loaders/kar/DL/INSTALL.sh
	cd ${WRKSRC}/ncbi-vdb/build && cmake .. && make

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*.${DISTVERSION}
	${MV} ${STAGEDIR}${PREFIX}/share/examples ${STAGEDIR}${PREFIX}/share/examples-sratools
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MV} ${STAGEDIR}${PREFIX}/share/examples-sratools/* ${STAGEDIR}${EXAMPLESDIR}
	${RMDIR} ${STAGEDIR}${PREFIX}/share/examples-sratools
	${MV} ${STAGEDIR}${PREFIX}/share/examples-java ${STAGEDIR}${EXAMPLESDIR}/java
	${MV} ${STAGEDIR}${PREFIX}/share/examples-python ${STAGEDIR}${EXAMPLESDIR}/python

post-stage-EXAMPLES-off:
	${RM} -r ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
