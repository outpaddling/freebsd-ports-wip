PORTNAME=	corefm
DISTVERSION=	4.3.0
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	File manager tool from Cubo Core
WWW=		https://gitlab.com/cubocore/corefm

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

# Not sure if multimedia/libzen is equivalent to ZenLib
LIB_DEPENDS=	libcprime-core.so:wip/libcprime \
		libcsys.so:wip/libcsys
RUN_DEPENDS=	coregarage:wip/coregarage

USES=		cmake localbase:ldflags qt:5
USE_QT=		buildtools_build core gui qmake_build widgets
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_COMMIT=	2579863ef39759c95f7547fdc750db44905da46c

PLIST_FILES=	bin/corefm \
		share/applications/org.cubocore.CoreFM.desktop \
		share/icons/hicolor/scalable/apps/org.cubocore.CoreFM.svg

pre-configure:
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/corefm|${PREFIX}/bin/corefm|g' \
		${WRKSRC}/org.cubocore.CoreFM.desktop

.include <bsd.port.mk>
