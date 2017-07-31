# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	makedepf90
PORTVERSION=	2.8.9
CATEGORIES=	wip

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Generate include dependencies for Fortran code

LICENSE=	GPLv3

USES=		gmake tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	a7044043d9b363ab563ef995b069adf477fe2c42

WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

ALL_TARGET=	makedepf90
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/makedepf90 share/man/man1/makedepf90.1

.include <bsd.port.mk>
