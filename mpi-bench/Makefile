# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	mpi-bench
PORTVERSION=	0.1.1
CATEGORIES=	wip net

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Simple, user-friendly MPI benchmark

LICENSE=	BSD2CLAUSE

LIB_DEPENDS+=	libmpi.so:net/openmpi

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

CC=	${LOCALBASE}/mpi/openmpi/bin/mpicc

PLIST_FILES=	bin/mpi-bench

.include <bsd.port.mk>
