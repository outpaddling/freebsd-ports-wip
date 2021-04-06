
PKGNAMESUFFIX=	-openmpi

# Would be nice to get this from Mk
# Include trailing / so that it can be used as ${MPIPREFIX}bin, etc.
MPIPREFIX=	mpi/openmpi/

MAINTAINER=	jwb@FreeBSD.org

LIB_DEPENDS+=	libmpi.so:net/openmpi

MASTERDIR=	${.CURDIR}/../fvcom

MAKE_ARGS+=	FC=${LOCALBASE}/${MPIPREFIX}bin/mpif90 \
		PORT_CPP_FLAGS+=-DMULTIPROCESSOR

.include "${MASTERDIR}/Makefile"
