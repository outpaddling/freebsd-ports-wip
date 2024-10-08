PORTNAME=	ti99sim
DISTVERSION=	0.16.0-6
DISTVERSIONSUFFIX=	-g6e2ba5c
CATEGORIES=	wip emulators
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	SDL-based TI-99/4a simulator
WWW=		https://www.mrousseau.org/programs/ti99sim/

LICENSE=	GPLv3

USES=		gmake sdl ssl tar:xz
USE_SDL=	sdl2
USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

MAKE_ARGS=	DATA_DIR=${STAGEDIR}${DATADIR} \
		BIN_DIR=${STAGEDIR}${DATADIR}/bin \
		SYS_BIN=${STAGEDIR}${PREFIX}/bin

post-stage:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/scripts/ti99sim-setup
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/ti99sim-setup ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
