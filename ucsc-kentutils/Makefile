# $FreeBSD$

PORTNAME=	ucsc-kentutils
DISTVERSION=	412
CATEGORIES=	wip biology perl5 python
MASTER_SITES=	http://hgdownload.cse.ucsc.edu/admin/exe/userApps.archive/
DISTNAME=	userApps.v${PORTVERSION}.src

MAINTAINER=	bacon@moray.acadix.biz
COMMENT=	Convert a bedGraph file to bigWig format

LICENSE=	UCSC
LICENSE_NAME=   UCSC Genome Browser License
LICENSE_TEXT=   License required for commercial download and installation of \
		most binaries and source code.
LICENSE_PERMS=  dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libiconv.so:converters/libiconv \
		libmysqlclient.so:databases/mysql57-client \
		libpng.so:graphics/png
RUN_DEPENDS=	bash:shells/bash

USES=		gmake localbase:ldflags shebangfix perl5 python:3.6+ ssl tar:tgz

SHEBANG_FILES=	kent/src/checkUmask.sh \
		kent/src/utils/bigHeat \
		kent/src/utils/chromToUcsc/chromToUcsc \
		kent/src/utils/tdbRename \
		kent/src/utils/tdbSort \
		kent/src/utils/trackDbIndexBb/trackDbIndexBb \
		kent/src/utils/ucscApiClient \
		kent/src/utils/webSync

WRKSRC=		${WRKDIR}/userApps
CFLAGS+=	-fcommon
MAKEFILE=	[Mm]akefile
MAKE_ENV+=	LOCALBASE=${LOCALBASE} BINDIR=${WRKSRC}/bin

SUB_FILES=	ucsc-shell

pre-configure:
	${MV} ${WRKSRC}/kent/src/inc/uuid.h ${WRKSRC}/kent/src/inc/my_uuid.h

# Build only non-commercial tools
do-build:
	${MKDIR} ${WRKSRC}/bin
	(cd ${WRKSRC}/kent/src/lib && ${DO_MAKE_BUILD})
	(cd ${WRKSRC}/kent/src/htslib && ${DO_MAKE_BUILD})
	(cd ${WRKSRC}/kent/src/jkOwnLib && ${DO_MAKE_BUILD})
	(cd ${WRKSRC}/kent/src/hg/lib && ${DO_MAKE_BUILD})
	(cd ${WRKSRC}/kent/src/utils && ${DO_MAKE_BUILD})

do-install:
	${MKDIR} ${WRKSRC}/scripts ${WRKSRC}/binaries
	${CP} $$(file work/userApps/bin/* | fgrep ELF | cut -d : -f 1) \
		${WRKSRC}/binaries
	${CP} $$(file work/userApps/bin/* | fgrep -v ELF | cut -d : -f 1) \
		${WRKSRC}/scripts
	${MKDIR} ${STAGEDIR}${PREFIX}/kentUtils/bin
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/* \
		${STAGEDIR}${PREFIX}/kentUtils/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* \
		${STAGEDIR}${PREFIX}/kentUtils/bin
	${INSTALL_SCRIPT} ${WRKDIR}/ucsc-shell \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
