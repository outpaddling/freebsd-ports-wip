# Created by: Jason Bacon <jwb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flann
PORTVERSION=	1.8.4
CATEGORIES=	wip science
MASTER_SITES=	http://www.cs.ubc.ca/research/flann/uploads/FLANN/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fast approximate nearest neighbor searches in high dimensional spaces

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	libhdf5.so:science/hdf5
LIB_DEPENDS+=	libsz.so:science/szip
LIB_DEPENDS+=	libgtest.so:devel/googletest

# FIXME: Should not be needed and isn't on outpaddling.cs
CXXFLAGS+=	-I${LOCALBASE}/include

USES=		cmake:outsource python zip

# FIXME: Matlab bindings can be on as an option with Octave as a dep
# FIXME: Python installs files outside stagedir
CMAKE_ARGS+=	-DBUILD_MATLAB_BINDINGS:BOOL=off \
		-DBUILD_PYTHON_BINDINGS:BOOL=off
CMAKE_VERBOSE=	yes

# post-install:
# 	${STRIP_CMD} ${STAGEDIR}${DATADIR}/octave/nearest_neighbors.mex

.include <bsd.port.mk>
