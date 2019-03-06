# $FreeBSD$

PORTNAME=	sdcc
PORTVERSION=	2.9.0
DISTVERSIONPREFIX=	src-
CATEGORIES=	wip lang
MASTER_SITES=	SF

MAINTAINER=	tijl@coosemans.org
COMMENT=	Small Device C Compiler

LICENSE=	GPLv3

BUILD_DEPENDS=	gputils==1.4.2.1:wip/gputils
RUN_DEPENDS=	gputils==1.4.2.1:wip/gputils

USES=		gmake localbase readline:port tar:bzip2

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
