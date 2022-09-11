PORTNAME=	mpi-bench
PORTVERSION=	0.1.1
CATEGORIES=	wip net

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Simple, user-friendly MPI benchmark
WWW=		https://github.com/outpaddling/mpi-bench

LICENSE=	BSD2CLAUSE

LIB_DEPENDS+=	libmpi.so:net/openmpi

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

CC=	${LOCALBASE}/mpi/openmpi/bin/mpicc

PLIST_FILES=	bin/mpi-bench

.include <bsd.port.mk>
