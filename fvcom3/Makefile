PORTNAME=	fvcom
PORTVERSION=	3.1.6
CATEGORIES=	wip science
MASTER_SITES=	http://fvcom.smast.umassd.edu/FVCOM/index.html/
DISTNAME=	fvcom316
EXTRACT_SUFX=	.tgz

WRKSRC=		FVCOM3.1.6_source

USE_GMAKE=	yes

#WITH_MPI=	yes

# Concatenate suffix for each build option.
# Make's += inserts space, and make complains about recursive expressions
# if we use VAR= ${VAR}value, so trick it by shelling out and using echo.
.ifdef WITH_MPI
PKGNAMESUFFIX+=	-mpi
.endif
.ifdef WITH_SPHERICAL
PKGNAMESUFFIX!=	echo ${PKGNAMESUFFIX}'-spherical'
.endif

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Unstructured Grid Finite Volume Coastal Ocean Model

# Check netcdf lib for Fortran support!
LIB_DEPENDS=	netcdf:science/netcdf \
		lapack:math/lapack \
		blas:math/lapack

USE_FORTRAN=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/fvcom_source_mpi

.include <bsd.port.pre.mk>

.ifdef WITH_MPI
LIB_DEPENDS+=	mpi:net/openmpi
.endif

PLIST_FILES=	bin/${PORTNAME}${PKGNAMESUFFIX}

# FVCOM Makefile flags
.ifdef WITH_MPI
MAKE_ARGS+=	FC=${LOCALBASE}/mpi/openmpi/bin/mpif90 PORT_CPP_FLAGS+=-DMULTIPROCESSOR
.endif
.ifdef WITH_SPHERICAL
MAKE_ARGS+=	PORT_CPP_FLAGS+=-DSPHERICAL
.endif

.if !defined(PACKAGE_BUILDING) && \
    !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
pre-everything::
	@${PRINTF} "\nPlease register at http://fvcom.smast.umassd.edu/FVCOM/index.html in order to download the source code ${DISTNAME}${EXTRACT_SUFX} and place it in ${DISTDIR}.\n\n" | ${FMT}
	@${FALSE}
.endif

post-extract:
	${RM} ${WRKSRC}/input/ts_assim_julian/makedepends.orig

pre-build:
	(cd ${WRKSRC}/libs && ${GMAKE} FC=${FC})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fvcom \
		${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.post.mk>
