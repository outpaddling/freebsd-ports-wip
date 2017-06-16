# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	merlin
PORTVERSION=	1.1.2
CATEGORIES=	wip biology
MASTER_SITES=	http://csg.sph.umich.edu/abecasis/Merlin/download/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Sparse trees to represent gene flow in pedigrees

LICENSE=	BSD3CLAUSE

USES=		gmake

# Depends on pedstats
RUN_DEPENDS+=	pedstats:wip/pedstats

INSTALL_TARGET=	INSTALLDIR=${STAGEDIR}${PREFIX}/bin install

.include <bsd.port.mk>
