PORTNAME=	coreterminal
DISTVERSION=	4.3.0
PORTREVISION=	2
CATEGORIES=	wip x11

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Terminal emulator from the CoreApps family

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libqtermwidget5.so:x11-toolkits/qtermwidget \
		libcprime-core.so:wip/libcprime
RUN_DEPENDS=	coregarage:wip/coregarage

USES=		cmake localbase:ldflags qt:5
USE_QT=		buildtools_build core gui qmake_build serialport widgets
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_COMMIT=	679b317d1612dcdd54596ba5bf313d60bebc808e

PLIST_FILES=	bin/coreterminal \
		share/applications/org.cubocore.CoreTerminal.desktop \
		share/icons/hicolor/scalable/apps/org.cubocore.CoreTerminal.svg

pre-configure:
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/coreterminal|${PREFIX}/bin/coreterminal|g' \
		${WRKSRC}/org.cubocore.CoreTerminal.desktop

.include <bsd.port.mk>
