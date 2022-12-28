PORTNAME=	corestats
DISTVERSION=	4.3.0
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	System resource viewer for C Suite
WWW=		https://gitlab.com/cubocore/corestats

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

# lm_sensors is Linux-only.  We'll need a sysctl interface to gather
# sensor data on FreeBSD.
LIB_DEPENDS=	libcprime-core.so:wip/libcprime
		#libcsys-core.so:wip/libcsys
RUN_DEPENDS=	coregarage:wip/coregarage

USES=		cmake localbase:ldflags qt:5
USE_QT=		buildtools:build core gui qmake:build serialport widgets
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_COMMIT=	eb5e790587a040f12820d0ac6711e6ab30148859

PLIST_FILES=	bin/coreterminal \
		share/applications/org.cubocore.CoreTerminal.desktop \
		share/icons/hicolor/scalable/apps/org.cubocore.CoreTerminal.svg

pre-configure:
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/coreterminal|${PREFIX}/bin/coreterminal|g' \
		${WRKSRC}/org.cubocore.CoreTerminal.desktop

.include <bsd.port.mk>
