# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD: head/science/meep/Makefile 369434 2014-09-28 03:41:24Z danilo $

PORTNAME=	meep
PORTVERSION=	1.2.1
CATEGORIES=	wip science
MASTER_SITES=	http://ab-initio.mit.edu/meep/

MAINTAINER=	devel@stasyan.com
COMMENT=	FDTD simulation software to model electromagnetic systems

BUILD_DEPENDS=	harminv:science/harminv \
		gsed:textproc/gsed
LIB_DEPENDS=	libguile.so:lang/guile \
		libblas.so:math/blas \
		libctl.so:science/libctl \
		libhdf5.so:science/hdf5
RUN_DEPENDS=	harminv:science/harminv

GNU_CONFIGURE=	yes
USE_GCC=	yes
USES=		fortran gettext gmake iconv libtool pathfix pkgconfig
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-fPIC
CXXFLAGS+=	-fPIC
LDFLAGS+=	-L${LOCALBASE}/lib -fPIC
MAKE_ARGS+=	CC="${CC}" CXX="${CXX}"

OPTIONS_DEFINE=		OPENMPI
OPTIONS_DEFAULT=	OPENMPI
OPENMPI_DESC=		MPI support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENMPI}
BUILD_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpiCC:net/openmpi
RUN_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpirun:net/openmpi
CONFIGURE_ARGS+=--with-mpi
CONFIGURE_ENV+=	MPICXX=${LOCALBASE}/mpi/openmpi/bin/mpiCC
CFLAGS+=	-I${LOCALBASE}/mpi/openmpi/include
PLIST_SUB+=	MPI="" NOMPI="@comment "
.else
CONFIGURE_ARGS+=--without-mpi
PLIST_SUB+=	MPI="@comment " NOMPI=""
.endif

.include <bsd.port.mk>
