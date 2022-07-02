PORTNAME=	libcprime
DISTVERSION=	4.3.0
PORTREVISION=	1
CATEGORIES=	wip deskutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Library for bookmarking, saving recent activites, managing settings

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake qt:5
USE_QT=		buildtools_build core dbus gui network qmake_build widgets
USE_LDCONFIG=	yes
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_COMMIT=	48979c0baf06dfbdce1c297a14fa182bc98922e6

.include <bsd.port.mk>
