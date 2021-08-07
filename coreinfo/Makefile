PORTNAME=	coreinfo
DISTVERSION=	4.3.0
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	System resource viewer for C Suite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

# Not sure if multimedia/libzen is equivalent to ZenLib
LIB_DEPENDS=	libcprime-core.so:wip/libcprime \
		libzen.so:multimedia/libzen \
		libmediainfo.so:multimedia/libmediainfo
RUN_DEPENDS=	coregarage:wip/coregarage

USES=		cmake localbase:ldflags qt:5
USE_QT=		buildtools_build core gui qmake_build serialport widgets
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_COMMIT=	2cdd1ca831b636425c773f5bf9c7ef854435b74e

PLIST_FILES=	bin/coreinfo \
		share/applications/org.cubocore.CoreInfo.desktop \
		share/icons/hicolor/scalable/apps/org.cubocore.CoreInfo.svg

pre-configure:
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/coreinfo|${PREFIX}/bin/coreinfo|g' \
		${WRKSRC}/org.cubocore.CoreInfo.desktop

.include <bsd.port.mk>
