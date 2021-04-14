# $FreeBSD$

PORTNAME=	ucsc-kentutils
DISTVERSION=	412
CATEGORIES=	wip biology perl5 python
MASTER_SITES=	http://hgdownload.cse.ucsc.edu/admin/exe/userApps.archive/
DISTNAME=	userApps.v${PORTVERSION}.src

MAINTAINER=	bacon@moray.acadix.biz
COMMENT=	Convert a bedGraph file to bigWig format

# A lie.  Create custom license.
LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libiconv.so:converters/libiconv \
		libmysqlclient.so:databases/mysql57-client
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
LDFLAGS+=	-L${LOCALBASE}/lib -liconv

pre-configure:
	${MV} ${WRKSRC}/kent/src/inc/uuid.h ${WRKSRC}/kent/src/inc/my_uuid.h

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

.include <bsd.port.mk>
