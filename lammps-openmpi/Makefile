# Created by:	Jason Bacon
# $FreeBSD$
#
# FIXME: Picks up mpich2 if present

PKGNAMESUFFIX=	-openmpi

MAINTAINER=	bacon4000@gmail.com

LICENSE=	GPLv1

BUILD_DEPENDS+=	${LOCALBASE}/mpi/openmpi/lib/libmpi.so:net/openmpi
RUN_DEPENDS+=	${LOCALBASE}/mpi/openmpi/lib/libmpi.so:net/openmpi

MASTERDIR=	${.CURDIR}/../lammps

ALL_TARGET=	FreeBSD-openmpi
INSTALL_PREFIX=	${PREFIX}/mpi/openmpi

PLIST_FILES=	mpi/openmpi/bin/lmp-openmpi

.include "${MASTERDIR}/Makefile"
