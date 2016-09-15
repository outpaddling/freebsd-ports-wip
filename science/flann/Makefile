# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	flann
PORTVERSION=	1.8.4
CATEGORIES=	science
MASTER_SITES=	http://www.cs.ubc.ca/research/flann/uploads/FLANN/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Fast approximate nearest neighbor searches in high dimensional spaces

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	libhdf5.so:science/hdf5
LIB_DEPENDS+=	libsz.so:science/szip

USES=		cmake:outsource zip

LDFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib/octave/4.0.0 -loctave

# FIXME: Make octave an option
post-install:
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/octave/nearest_neighbors.mex

.include <bsd.port.mk>
