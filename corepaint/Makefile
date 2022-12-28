PORTNAME=	corepaint
DISTVERSION=	4.3.0
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Simple paint app from CuboCore
WWW=		https://gitlab.com/cubocore/corepaint

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcprime-core.so:wip/libcprime
RUN_DEPENDS=	coregarage:wip/coregarage

USES=		cmake desktop-file-utils localbase:ldflags qt:5
USE_QT=		buildtools:build core gui qmake:build widgets
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_COMMIT=	20b1573432200aec934dcd1e7d42e6363086dc01

PLIST_FILES=	bin/corepaint \
		share/applications/org.cubocore.CorePaint.desktop \
		share/icons/hicolor/scalable/apps/org.cubocore.CorePaint.svg

pre-configure:
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/corepaint|${PREFIX}/bin/corepaint|g' \
		${WRKSRC}/org.cubocore.CorePaint.desktop

.include <bsd.port.mk>
