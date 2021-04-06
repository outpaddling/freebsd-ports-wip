
PORTNAME=	atomistix-installer
PORTVERSION=	0.1
CATEGORIES=	wip science
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Easy installation of Linux Atomistix(r) on FreeBSD

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	/compat/linux/lib/libudev.so.0:wip/linux-c6-libudev

USES=		tar:xz
USE_LINUX=	yes
USE_LINUX_APPS=	dri devtools

NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/atomistix-patch

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/atomistix-patch \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/atomistix-patch.sed \
		${STAGEDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
