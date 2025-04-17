PORTNAME=	openhospital
DISTVERSIONPREFIX=	v
DISTVERSION=	1.14.2
CATEGORIES=	wip misc java
# Github tags only contain docs
MASTER_SITES=	https://github.com/informatici/openhospital/releases/download/v1.14.2/
PKGNAMESUFFIX=	-client
DISTNAME=	OpenHospital-v1.14.2-multiarch-client

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free and open-source Health Information Management System (HIMS)
WWW=		https://example.com/openhospital-client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		java shebangfix zip

SHEBANG_FILES=	oh.sh

NO_BUILD=	yes
NO_ARCH=	yes

# To-do: Patch files for FreeBSD and install whatever is necessary to
# make the client run.   Probably should be a script in ${PREFIX}/bin
# to launch the Java app.

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/oh/bin/*.jar ${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.mk>
