# $FreeBSD$
#
# TODO:
# Consistently crashes on login to the VPN server

PORTNAME=	Linux-VPN-JunosPulse
PORTVERSION=	5.1
CATEGORIES=	wip net linux
MASTER_SITES=	
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.i386.rpm

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Junos Pulse Secure Client

USE_LINUX=      yes
# USE_LINUX_APPS= ncurses-base dri devtools
USE_JAVA=       yes
JAVA_VERSION=   1.6+
JAVA_OS=        linux
JAVA_RUN=       yes

NO_BUILD=	yes

do-install:
	cd ${WRKDIR} && ${COPYTREE_BIN} usr ${STAGEDIR}${LINUXBASE}
	${INSTALL_SCRIPT} ${FILESDIR}/pulse-secure ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
