PORTNAME=	ti99sim
DISTVERSION=	0.16.0
CATEGORIES=	wip emulators
MASTER_SITES=	https://www.mrousseau.org/programs/ti99sim/archives/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	SDL-based TI-99/4a simulator
WWW=		https://www.mrousseau.org/programs/ti99sim/

LICENSE=	GPLv3

USES=		gmake sdl tar:xz
USE_SDL=	sdl2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_JOBS_UNSAFE=	yes

MAKE_ENV=	DATA_DIR=${STAGEDIR}/${DATADIR} \
		SYS_BIN=${STAGEDIR}${PREFIX}/bin \
		BIN_DIR=${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
