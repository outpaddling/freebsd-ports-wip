PORTNAME=	coregarage
DISTVERSION=	4.2.0
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Settings manager for C Suite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libarchiveqt5.so:wip/libarchive-qt \
		libcprime-core.so:wip/libcprime

USES=		cmake localbase:ldflags qt:5
USE_QT=		buildtools_build core gui qmake_build widgets
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_COMMIT=	dc9a23f3b3e309427585eb69f80279c24b781e5d

PLIST_FILES=	bin/coregarage \
		share/applications/org.cubocore.CoreGarage.desktop \
		share/icons/hicolor/scalable/apps/org.cubocore.CoreGarage.svg

.include <bsd.port.mk>
