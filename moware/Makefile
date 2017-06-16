# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	moware
PORTVERSION=	1.0
CATEGORIES=	wip devel
MASTER_SITES=	ftp://ftp.ifremer.fr/ifremer/fortran90/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Fortran 90 preprocessor and utilities

USES=		fortran gmake

post-patch:
	cd ${WRKSRC} && ${MAKE} clean

.include <bsd.port.mk>
