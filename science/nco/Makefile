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

BUILD_DEPENDS+=	${PORTSDIR}/devel/bison:${PORTSDIR}/textproc/flex \
		${PORTSDIR}/math/gsl:${PORTSDIR}/science/hdf5 \
		${PORTSDIR}/science/netcdf:${PORTSDIR}/science/udunits \
		${PORTSDIR}/devel/antlr:${PORTSDIR}/textproc/expat2

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
