PORTNAME=	coreterminal
DISTVERSION=	4.2.0
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Terminal emulator from the CoreApps family

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libqtermwidget5.so:x11-toolkits/qtermwidget \
		libcprime-core.so:wip/libcprime

USES=		cmake localbase:ldflags qt:5
USE_QT=		buildtools_build core gui serialport widgets
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_COMMIT=	5cd6341562344701c34b0390eb4b9c5fa37bbe0f

PLIST_FILES=	bin/coreterminal \
		share/applications/org.cubocore.CoreTerminal.desktop \
		share/icons/hicolor/scalable/apps/org.cubocore.CoreTerminal.svg

.include <bsd.port.mk>
