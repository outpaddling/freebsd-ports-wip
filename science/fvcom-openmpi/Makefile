# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD: ports/science/fvcom-mpi/Makefile,v 1.1 2013/02/20 17:46:51 svnexp Exp $

PKGNAMESUFFIX=	-openmpi

# Would be nice to get this from Mk
# Include trailing / so that it can be used as ${MPIPREFIX}bin, etc.
MPIPREFIX=	mpi/openmpi/

MAINTAINER=	jwbacon@tds.net

LIB_DEPENDS+=	mpi:${PORTSDIR}/net/openmpi

MASTERDIR=	${.CURDIR}/../fvcom

MAKE_ARGS+=	FC=${LOCALBASE}/${MPIDIR}/bin/mpif90 \
		PORT_CPP_FLAGS+=-DMULTIPROCESSOR

.include "${MASTERDIR}/Makefile"
