PORTNAME=	merlin
PORTVERSION=	1.1.2
CATEGORIES=	wip biology
MASTER_SITES=	http://csg.sph.umich.edu/abecasis/Merlin/download/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Sparse trees to represent gene flow in pedigrees

LICENSE=	BSD3CLAUSE

USES=		gmake

# Depends on pedstats
RUN_DEPENDS+=	pedstats:wip/pedstats

INSTALL_TARGET=	INSTALLDIR=${STAGEDIR}${PREFIX}/bin install

.include <bsd.port.mk>
