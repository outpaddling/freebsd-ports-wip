# $FreeBSD$

PORTNAME=	spcm
PORTVERSION=	0.4.1
CATEGORIES=	wip sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://outpaddling.mooo.com/~bacon/Acadix/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for building and managing HPC clusters

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	auto-admin>=0.4.9:wip/auto-admin \
		${PYTHON_PKGNAMEPREFIX}hostlist:wip/py-hostlist

USES=		tar:xz

MAKE_ENV+=	PREFIX=${PREFIX} DATADIR=${DATADIR}

post-install:
	if [ -e /usr/local/cluster ] && [ 0$(ls ${PREFIX}/etc/spcm) = 0 ]; then \
		mv /usr/local/cluster/* ${PREFIX}/etc/spcm; \
		rmdir /usr/local/cluster; \
	fi
	${CHMOD} -R a+rX ${PREFIX}/etc/spcm

.include <bsd.port.mk>
