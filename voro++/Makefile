# $FreeBSD: head/science/voro++/Makefile 460452 2018-01-31 01:07:07Z jwb $

PORTNAME=	voro++
DISTVERSION=	0.4.6
PORTREVISION=	1
CATEGORIES=	wip science
MASTER_SITES=	http://math.lbl.gov/voro++/download/dir/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Three-dimensional computations of the Voronoi tessellation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_LDCONFIG=	yes

CFLAGS+=	-fPIC

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/voro++

.include <bsd.port.mk>
