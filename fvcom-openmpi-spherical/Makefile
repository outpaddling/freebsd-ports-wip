# New ports collection makefile for:	fvcom-mpi
# Date created:			31 Mar 2012
# Whom:				Jason Bacon <jwb@FreeBSD.org>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../fvcom

PKGNAMESUFFIX=	-openmpi-spherical

BUILD_DEPENDS+=	${LOCALBASE}/mpi/openmpi/lib/libmpi.so:net/openmpi
RUN_DEPENDS+=	${LOCALBASE}/mpi/openmpi/lib/libmpi.so:net/openmpi

MAKE_ARGS+=	FC=${LOCALBASE}/mpi/openmpi/bin/mpif90 \
		PORT_CPP_FLAGS+='-DMULTIPROCESSOR -DSPHERICAL'

.include "../fvcom/Makefile"
