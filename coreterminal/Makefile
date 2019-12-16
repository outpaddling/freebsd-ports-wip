# $FreeBSD$

PORTNAME=	coreterminal
#DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.1
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
GL_COMMIT=	f6612c51d643a8412e61c0aa6154561c4e6b642d

.include <bsd.port.mk>
