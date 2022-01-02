PORTNAME=	spcm
DISTVERSION=	0.5.5-8
DISTVERSIONSUFFIX=	-gc36af62
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for building and managing HPC clusters

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	auto-admin>=0.7.8.16:wip/auto-admin

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_PROJECT=	SPCM

MAKE_ENV+=	DATADIR=${DATADIR}

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cluster-passwd

.include <bsd.port.mk>
