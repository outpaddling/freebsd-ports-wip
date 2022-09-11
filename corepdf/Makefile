PORTNAME=	corepdf
DISTVERSION=	4.3.0
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	PDF viewer from the CoreApps family
WWW=		https://gitlab.com/cubocore/corepdf

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5 \
		libcprime-core.so:wip/libcprime
RUN_DEPENDS=	coregarage:wip/coregarage

USES=		cmake localbase:ldflags qt:5
USE_QT=		buildtools_build core gui qmake_build serialport widgets
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_COMMIT=	ee6897f0032763ae1a0569980715987c2bdc6d5b

PLIST_FILES=	bin/corepdf \
		share/applications/org.cubocore.CorePDF.desktop \
		share/icons/hicolor/scalable/apps/org.cubocore.CorePDF.svg

pre-configure:
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/corepdf|${PREFIX}/bin/corepdf|g' \
		${WRKSRC}/org.cubocore.CorePDF.desktop

.include <bsd.port.mk>
