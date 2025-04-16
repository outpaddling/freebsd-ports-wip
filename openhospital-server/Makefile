PORTNAME=	openhospital
DISTVERSIONPREFIX=	v
DISTVERSION=	1.14.2
CATEGORIES=	wip net
# Github tags only contain docs
MASTER_SITES=	https://github.com/informatici/openhospital/releases/download/v1.14.2/
PKGNAMESUFFIX=	-server
DISTNAME=	OpenHospital-v${DISTVERSION}-linux_x86_64-portable

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free and open-source Health Information Management System (HIMS)
WWW=		https://example.com/oh-server

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES+=		mysql:server shebangfix

SHEBANG_FILES=	oh.sh

NO_BUILD=	yes
NO_ARCH=	yes

# To-do: Patch files for FreeBSD and install whatever is necessary to
# make the client run.   Probably should be a script in ${PREFIX}/bin
# to launch the Java app.

do-install:
	# FIXME: oh.sh probably needs patching
	${INSTALL_SCRIPT} ${WRKSRC}/oh.sh ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
