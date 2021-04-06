
PORTNAME=	moware
PORTVERSION=	1.0
CATEGORIES=	wip devel
MASTER_SITES=	ftp://ftp.ifremer.fr/ifremer/fortran90/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fortran 90 preprocessor and utilities

USES=		fortran gmake

post-patch:
	cd ${WRKSRC} && ${MAKE} clean

.include <bsd.port.mk>
