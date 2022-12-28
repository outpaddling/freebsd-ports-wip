PORTNAME=	libcsys
DISTVERSION=	4.2.2
CATEGORIES=	wip devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Manage drive and get system resource information
WWW=		https://gitlab.com/cubocore/libcsys

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libudisks2.so:sysutils/libudisks

USES=		cmake qt:5
# network is not listed as a dep on dev site
USE_QT=		buildtools:build core dbus gui network qmake:build widgets
USE_LDCONFIG=	yes
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_COMMIT=	f4a677d137ef44f7c696a1c327cec00ed3a0e25c

.include <bsd.port.mk>
