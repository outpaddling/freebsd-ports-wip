PORTNAME=	gputils
DISTVERSION=	1.4.2-1
CATEGORIES=	wip devel
MASTER_SITES=	SF/gputils/gputils/${PORTVERSION:R}
PKGNAMESUFFIX=	14

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Utilities for Microchip PIC microcontrollers
WWW=		https://gputils.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	gplink-[0-9]*
GNU_CONFIGURE=	yes
USES=		bison gmake
CONFIGURE_ARGS= --disable-dependency-tracking --disable-html-doc
WRKSRC=		${WRKDIR}/gputils-${PORTVERSION:R}

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>=2.5.35:${PORTSDIR}/textproc/flex
CONFIGURE_ARGS+=LEX=${LOCALBASE}/bin/flex
.endif

.include <bsd.port.mk>
