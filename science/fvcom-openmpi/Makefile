# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD: head/science/fvcom-mpi/Makefile 351165 2014-04-13 00:17:45Z danilo $

PKGNAMESUFFIX=	-openmpi

# Would be nice to get this from Mk
# Include trailing / so that it can be used as ${MPIPREFIX}bin, etc.
MPIPREFIX=	mpi/openmpi/

MAINTAINER=	bacon4000@gmail.com

LIB_DEPENDS+=	libmpi.so:${PORTSDIR}/net/openmpi

MASTERDIR=	${.CURDIR}/../fvcom

MAKE_ARGS+=	FC=${LOCALBASE}/${MPIPREFIX}bin/mpif90 \
		PORT_CPP_FLAGS+=-DMULTIPROCESSOR

.include "${MASTERDIR}/Makefile"
