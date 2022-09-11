PORTNAME=	mcc18-wrapper
PORTVERSION=	0.2
CATEGORIES=	wip lang
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Wrappers for Windows based Microchip MCC18 and Wine
WWW=		https://www.microchip.com

DEPENDS_RUN=	wine:emulators/wine

.include <bsd.port.pre.mk>

#ONLY_FOR_ARCHS!=awk '$$1 == "ONLY_FOR_ARCHS=" { print $$2,$$3,$$4,$$5 }' \
#		emulators/wine/Makefile

NO_BUILD=	yes

PKG_MESSAGE=	${WRKDIR}/pkg-message
PLIST_FILES=	bin/mcc18 \
		bin/mpasm \
		bin/mplib \
		bin/mplink \
		bin/mcc18_check

MAN1=		mcc18.1 mpasm.1 mplib.1 mplink.1

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/mcc18 ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mpasm ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mplib ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mplink ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mcc18_check ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mcc18.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/mcc18.1 ${MAN1PREFIX}/man/man1/mpasm.1
	${INSTALL_MAN} ${WRKSRC}/mcc18.1 ${MAN1PREFIX}/man/man1/mplib.1
	${INSTALL_MAN} ${WRKSRC}/mcc18.1 ${MAN1PREFIX}/man/man1/mplink.1

.include <bsd.port.post.mk>
