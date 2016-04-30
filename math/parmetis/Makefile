# New ports collection makefile for:	ParMETIS
# Date created:         19 May 99
# Whom:                 Eoin Lawless (eoin@maths.tcd.ie)
#
# $FreeBSD: ports/math/parmetis/Makefile,v 1.19 2011/11/19 09:04:39 bf Exp $
#

PORTNAME=	ParMetis
PORTVERSION=	4.0
CATEGORIES=	math parallel
MASTER_SITES=	http://glaros.dtc.umn.edu/gkhome/fetch/sw/parmetis/%SUBDIR%/
MASTER_SITE_SUBDIR=	. OLD
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A package for parallel (mpi) unstructured graph partitioning

OPTIONS=	OPENMPI "Use openmpi instead of mpich2" off

USE_CMAKE=	yes
USE_GMAKE=	yes

PORTDOCS=	manual.pdf
PLIST_FILES=	include/parmetis/parmetis.h \
		lib/parmetis/libmetis.a lib/parmetis/libparmetis.a
PLIST_DIRS=	include/parmetis lib/parmetis

.include <bsd.port.pre.mk>

.if defined(WITH_OPENMPI)
BUILD_DEPENDS=	${LOCALBASE}/mpi/openmpi/bin/mpicc:net/openmpi
RUN_DEPENDS=	${LOCALBASE}/mpi/openmpi/bin/mpirun:net/openmpi
MPICC=		${LOCALBASE}/mpi/openmpi/bin/mpicc
.else
BUILD_DEPENDS=	${LOCALBASE}/bin/mpicc:net/mpich2
RUN_DEPENDS=	${LOCALBASE}/bin/mpirun:net/mpich2
MPICC=		${LOCALBASE}/bin/mpicc
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|BUILDDIR =.*|BUILDDIR = build| ; \
		 s|make -C|$$(MAKE) -C|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|"-O3"|""|' ${WRKSRC}/metis/GKlib/GKlibSystem.cmake

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} config prefix="${PREFIX}" cc="${MPICC}"

do-install:
	@${MKDIR} ${PREFIX}/include/parmetis
	${INSTALL_DATA} ${WRKSRC}/include/parmetis.h ${PREFIX}/include/parmetis
	@${MKDIR} ${PREFIX}/lib/parmetis
	${INSTALL_DATA} ${WRKSRC}/build/libmetis/libmetis.a ${PREFIX}/lib/parmetis
	${INSTALL_DATA} ${WRKSRC}/build/libparmetis/libparmetis.a ${PREFIX}/lib/parmetis
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual/manual.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
