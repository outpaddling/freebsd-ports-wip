# $FreeBSD$

PORTNAME=	SPCM
DISTVERSION=	0.4.1-6
DISTVERSIONSUFFIX=	-gd45d355
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for building and managing HPC clusters

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	auto-admin>=0.6.3:wip/auto-admin \
		${PYTHON_PKGNAMEPREFIX}hostlist:wip/py-hostlist@${PY_FLAVOR}

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

MAKE_ENV+=	PREFIX=${PREFIX} DATADIR=${DATADIR}

.include <bsd.port.mk>
