
PORTNAME=	coreterminal
#DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	A terminal emulator from the CoreApps family.

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		qt:5
USE_QT=         buildtools_build core qmake_build
# USE_QT=         buildtools_build core gui qmake_build dbus linguisttools \
#                widgets x11extras
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_COMMIT=	fd82393c73bcd650f57a98e56eef2487713021a5

.include <bsd.port.mk>
