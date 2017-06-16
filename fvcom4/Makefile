# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD: head/science/fvcom/Makefile 437439 2017-04-01 15:23:30Z gerald $

PORTNAME=	fvcom
PORTVERSION=	4.0
CATEGORIES=	wip science
MASTER_SITES=	http://fvcom.smast.umassd.edu/FVCOM/index.html/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Unstructured Grid Finite Volume Coastal Ocean Model

# Check netcdf lib for Fortran support!
LIB_DEPENDS+=	libnetcdff.so:science/netcdf-fortran \
		liblapack.so:math/lapack \
		libblas.so:math/lapack

USES=		fortran

PLIST_FILES=	${MPIPREFIX}bin/${PORTNAME}${PKGNAMESUFFIX}

WRKSRC=		${WRKDIR}/FVCOM4.0

RESTRICTED=	Requires (free) registration

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTFILES})
IGNORE=	may not be redistributed because of licensing reasons.\
	Please register at http://fvcom.smast.umassd.edu/FVCOM/index.html\
	in order to download the source code ${DISTFILES}\
	and place it in ${DISTDIR}/${DIST_SUBDIR}/
.endif

MAKE_JOBS_UNSAFE=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${MPIPREFIX}bin
	${INSTALL_PROGRAM} ${WRKSRC}/fvcom \
		${STAGEDIR}${PREFIX}/${MPIPREFIX}bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.post.mk>
