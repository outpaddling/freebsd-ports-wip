
PORTNAME=	sdcc
PORTVERSION=	3.0.0
DISTVERSIONPREFIX=	src-
CATEGORIES=	wip lang
MASTER_SITES=	SF

MAINTAINER=	tijl@coosemans.org
COMMENT=	Small Device C Compiler

LICENSE=	GPLv3

BUILD_DEPENDS=	gputils==1.4.2.1:wip/gputils
RUN_DEPENDS=	gputils==1.4.2.1:wip/gputils

USES=		compiler:c++11-lang gmake localbase python readline shebangfix tar:bzip2

SHEBANG_FILES=	support/scripts/as2gbmap.py
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/sdcc
CONFIGURE_ARGS=	--datarootdir=${DATADIR} \
		--docdir=${DOCSDIR} \
		include_dir_suffix=include \
		lib_dir_suffix=lib

post-patch:
	@${REINPLACE_CMD} 's,[[:<:]]ARCH[[:>:]],PICARCH,g' \
		${WRKSRC}/device/lib/pic16/configure \
		${WRKSRC}/device/non-free/lib/pic16/configure \
		${WRKSRC}/device/lib/pic/Makefile.common.in \
		${WRKSRC}/device/lib/pic/Makefile.rules \
		${WRKSRC}/device/lib/pic/Makefile.rules \
		${WRKSRC}/device/lib/pic/Makefile.common.in \
		${WRKSRC}/device/lib/pic16/libc/Makefile.in \
		${WRKSRC}/device/lib/pic16/debug/Makefile.in \
		${WRKSRC}/device/lib/pic16/Makefile.in \
		${WRKSRC}/device/lib/pic16/startup/Makefile.in \
		${WRKSRC}/device/lib/pic16/libio/Makefile.in \
		${WRKSRC}/device/lib/pic16/libm/Makefile.in \
		${WRKSRC}/device/lib/pic16/libsdcc/Makefile.in \
		${WRKSRC}/device/non-free/lib/pic16/Makefile.in \
		${WRKSRC}/device/non-free/lib/pic16/libdev/Makefile.in \
		${WRKSRC}/device/non-free/lib/pic/Makefile.rules \
		${WRKSRC}/device/non-free/lib/pic/Makefile.common.in

.include <bsd.port.mk>
