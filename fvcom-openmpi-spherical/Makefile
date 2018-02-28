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
