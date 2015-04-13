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

GNU_CONFIGURE=	yes
USE_GCC=	yes
USES=		gmake

MAKE_JOBS_UNSAFE=	yes

BUILD_DEPENDS+=	bison:${PORTSDIR}/devel/bison \
		flex:${PORTSDIR}/textproc/flex \
		antlr:${PORTSDIR}/devel/antlr
LIB_DEPENDS=	libgsl.so:${PORTSDIR}/math/gsl \
		libhdf5.so:${PORTSDIR}/science/hdf5 \
		libnetcdf.so:${PORTSDIR}/science/netcdf \
		libudunits2.so:${PORTSDIR}/science/udunits \
		libexpat.so:${PORTSDIR}/textproc/expat2

post-configure:
	${REINPLACE_CMD} \
		-e 's|-D_POSIX_SOURCE||g' \
		`find ${WRKSRC} -name Makefile`

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
