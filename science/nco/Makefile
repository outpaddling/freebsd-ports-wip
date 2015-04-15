# Created by: Administrator <admin@FreeBSD-VM-1.meadows>
# $FreeBSD$

PORTNAME=	nco
PORTVERSION=	4.4.8
CATEGORIES=	science
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Manipulates and analyzes netCDF data

LICENSE=	GPLv3

BUILD_DEPENDS+=	bison:${PORTSDIR}/devel/bison \
		flex:${PORTSDIR}/textproc/flex \
		antlr:${PORTSDIR}/devel/antlr \
		makeinfo:${PORTSDIR}/print/texinfo
LIB_DEPENDS=	libgsl.so:${PORTSDIR}/math/gsl \
		libhdf5.so:${PORTSDIR}/science/hdf5 \
		libnetcdf.so:${PORTSDIR}/science/netcdf \
		libudunits2.so:${PORTSDIR}/science/udunits \
		libexpat.so:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	yes
USES=		gmake libtool
CONFIGURE_ENV=	ANTLR_ROOT=${PREFIX} \
		NETCDF_INC=${PREFIX}/include \
		NETCDF_LIB=${PREFIX}/lib

USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes

INSTALL_TARGET=	install-strip

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
