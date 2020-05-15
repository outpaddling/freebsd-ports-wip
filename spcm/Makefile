# $FreeBSD$

PORTNAME=	SPCM
PORTVERSION=	0.4.1
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for building and managing HPC clusters

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	auto-admin>=0.6.3:wip/auto-admin \
		${PYTHON_PKGNAMEPREFIX}hostlist:wip/py-hostlist@${PY_FLAVOR}

USES=		tar:xz
USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

MAKE_ENV+=	PREFIX=${PREFIX} DATADIR=${DATADIR}

.include <bsd.port.mk>
