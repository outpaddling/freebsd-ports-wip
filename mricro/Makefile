
PORTNAME=	mricro
PORTVERSION=	1.39
CATEGORIES=	wip science
MASTER_SITES=	http://www.sph.sc.edu/comd/rorden/ \
		http://www.neuro.mcw.edu/~bacon/Ports/distfiles/
PKGNAMEPREFIX=	linux-
DISTNAME=	mricrox

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Medical image viewer and converter

USE_LINUX=	yes
USE_XLIB=	yes

SUB_FILES=	pkg-message

NO_BUILD=	yes

WWW=		http://www.sph.sc.edu/comd/rorden/mricro.html

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/startmricro ${PREFIX}/bin
	${CP} -R ${WRKDIR}/mricro ${PREFIX}/bin
	${CHMOD} -R 555 ${PREFIX}/bin/startmricro ${PREFIX}/bin/mricro

post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.mk>
