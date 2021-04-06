
PORTNAME=	nco
PORTVERSION=	4.4.8
CATEGORIES=	wip science
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Manipulates and analyzes netCDF data

LICENSE=	GPLv3

# Building docs requires GNU nm, so install binutils and add
# $LOCALBASE/bin to PATH during configure and build stages.
BUILD_DEPENDS+=	bison:devel/bison \
		flex:textproc/flex \
		antlr:devel/antlr \
		makeinfo:print/texinfo \
		${LOCALBASE}/bin/nm:devel/binutils
LIB_DEPENDS=	libgsl.so:math/gsl \
		libhdf5.so:science/hdf5 \
		libnetcdf.so:science/netcdf \
		libudunits2.so:science/udunits \
		libexpat.so:textproc/expat2

GNU_CONFIGURE=	yes
USES=		gmake libtool
CONFIGURE_ENV=	ANTLR_ROOT=${PREFIX} \
		NETCDF_INC=${PREFIX}/include \
		NETCDF_LIB=${PREFIX}/lib \
		PATH=${LOCALBASE}/bin:$$PATH
MAKE_ENV+=	PATH=${LOCALBASE}/bin:$$PATH

USE_LDCONFIG=	yes

# MAKE_JOBS_UNSAFE=	yes

INSTALL_TARGET=	install-strip

INFO=		nco

post-configure:
	${REINPLACE_CMD} \
		-e 's|-D_POSIX_SOURCE||g' \
		`find ${WRKSRC} -name Makefile`
#	${REINPLACE_CMD} \
#		-e 's|man doc|man|g' \
#		${WRKSRC}/Makefile

#post-install:
#	${STRIP_CMD} \
#		${STAGEDIR}${PREFIX}/lib/libnco-4.4.8.so
#	${STRIP_CMD} \
#		${STAGEDIR}${PREFIX}/lib/libnco_c++-4.4.8.so

.include <bsd.port.mk>
