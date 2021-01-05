# $FreeBSD$

PORTNAME=	spcm
DISTVERSION=	0.4.2-40
DISTVERSIONSUFFIX=	-g7a0c83c
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for building and managing HPC clusters

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	auto-admin>=0.6.7.11:wip/auto-admin
# Causes python to be built from source when built from wip
# Add this after it's committed
#		${PYTHON_PKGNAMEPREFIX}hostlist:wip/py-hostlist@${PY_FLAVOR}

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_PROJECT=	SPCM

MAKE_ENV+=	PREFIX=${PREFIX} DATADIR=${DATADIR}

.include <bsd.port.mk>
