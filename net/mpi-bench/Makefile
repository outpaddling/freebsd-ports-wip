# Created by: Jason Bacon <bacon@sculpin.acadix.biz>
# $FreeBSD$

PORTNAME=	mpi-bench
PORTVERSION=	0.1.1
CATEGORIES=	net

MAINTAINER=	bacon@sculpin.acadix.biz
COMMENT=

LIB_DEPENDS+=	libmpi.so:net/openmpi

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

CC=	${LOCALBASE}/mpi/openmpi/bin/mpicc

PLIST_FILES=	bin/mpi-bench

.include <bsd.port.mk>
