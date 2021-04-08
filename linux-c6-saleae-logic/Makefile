PORTNAME=	logic
PORTVERSION=	1.1.30
CATEGORIES=	wip sysutils
MASTER_SITES=	http://downloads.saleae.com/betas/1.1.30/
DISTNAME=	Logic+${PORTVERSION}+\(32-bit\)

MAINTAINER=	jwb@FreeBSD.org
COMMENT=

ONLY_FOR_ARCHS= amd64 i386
USE_LINUX=      c6
# Need libusb, or bundled?
# USE_LINUX_APPS= libusb

USES=		zip
USE_LDCONFIG=	${PREFIX}/lib/Saleae

WRKSRC=		${WRKDIR}/Logic\ ${PORTVERSION}\ \(32-bit\)

NO_BUILD=	yes

do-install:
	brandelf -t Linux ${WRKSRC}/Logic
	${INSTALL_PROGRAM} ${WRKSRC}/Logic ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/Saleae
	${INSTALL_DATA} ${WRKSRC}/libAnalyzer.so ${STAGEDIR}${PREFIX}/lib/Saleae
	${INSTALL_DATA} ${WRKSRC}/Analyzers/* ${STAGEDIR}${PREFIX}/lib/Saleae

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
