# $FreeBSD$

PORTNAME=	miniconda-installer
PKGNAMEPREFIX=	linux-
DISTVERSION=	0.0.1
CATEGORIES=	wip sysutils

MAINTAINER=	bacon@moray.acadix.biz
COMMENT=	Aid for installing and using miniconda

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		linux
USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

NO_BUILD=	yes
PLIST_FILES=	bin/miniconda-installer

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/miniconda-installer \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
