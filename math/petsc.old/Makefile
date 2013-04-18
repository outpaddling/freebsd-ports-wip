# New ports collection makefile for:	petsc
# Date created:		2012-04-08
# Whom:			Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	petsc
#PORTVERSION=	3.1
PORTVERSION=	3.2
CATEGORIES=	math
MASTER_SITES=	http://ftp.mcs.anl.gov/pub/petsc/release-snapshots/
#DISTNAME=	${PORTNAME}-${PORTVERSION}-p8
DISTNAME=	${PORTNAME}-${PORTVERSION}-p7

MAINTAINER=	jwbacon@tds.net
COMMENT=	Parallel solution of partial differential equations

HAS_CONFIGURE=	yes
USE_PERL5=	yes
CONFIG_SHELL=	${PYTHONBIN}
CONFIGURE_ENV=	PETSC_DIR=${WRKSRC} TEMP=${WRKSRC}/temp
CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--with-error-checking=yes \
		--CPP=${CPP} \
		--CPPFLAGS=${CPPFLAGS} \
		--CFLAGS=${CFLAGS} \
		--CXXFLAGS=${CXXFLAGS} \
		--FFLAGS=${FFLAGS} \
		--LDFLAGS=${LDFLAGS} \
		--doCleanup=0 \
		--with-language=C \
		--with-c++-support \
		--with-fortran \
		--with-shared-libraries \
		--with-64-bit-indices=1 \
		--with-64-bit-pointers=1 \
		--with-pic \
		--with-mpi=0

#		--with-mpi-dir=${LOCALBASE}/mpi/openmpi \
#		--with-mpiexec=${LOCALBASE}/mpi/openmpi/bin/mpirun \
#		--with-mpi-compilers=1 \

USE_GMAKE=	yes
MAKEFILE=	makefile

MAKE_ENV+=	PETSC_DIR=${WRKSRC}

pre-configure:
	${MKDIR} ${WRKSRC}/temp

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
