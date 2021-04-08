PORTNAME=	sdcc
DISTVERSIONPREFIX=	src-
DISTVERSION=	2.9.0
CATEGORIES=	wip lang
MASTER_SITES=	SF
PKGNAMESUFFIX=	2

MAINTAINER=	tijl@coosemans.org
COMMENT=	Small Device C Compiler

LICENSE=	GPLv3

BUILD_DEPENDS=	gputils14==1.4.2.1:wip/gputils
RUN_DEPENDS=	gputils14==1.4.2.1:wip/gputils

USES=		compiler:c++11-lang gmake localbase readline tar:bzip2

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/sdcc
CONFIGURE_ARGS=	--datarootdir=${DATADIR} \
		--docdir=${DOCSDIR} \
		include_dir_suffix=include \
		lib_dir_suffix=lib

post-patch:
	@${REINPLACE_CMD} 's,ARCH,PICARCH,g' \
		${WRKSRC}/device/lib/pic/Makefile.common.in \
		${WRKSRC}/device/lib/pic/Makefile.rules \
		${WRKSRC}/device/lib/pic16/configure

.include <bsd.port.mk>
