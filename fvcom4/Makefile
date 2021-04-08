PORTNAME=	fvcom
PORTVERSION=	4.0
CATEGORIES=	wip science
MASTER_SITES=	http://fvcom.smast.umassd.edu/FVCOM/index.html/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Unstructured Grid Finite Volume Coastal Ocean Model

# Phony just to avoid ports delays for now
LICENSE=	BSD2CLAUSE

# Check netcdf lib for Fortran support!
LIB_DEPENDS+=	libnetcdff.so:science/netcdf-fortran \
		liblapack.so:math/lapack \
		libblas.so:math/lapack

USES=		fortran gmake

PLIST_FILES=	${MPIPREFIX}bin/${PORTNAME}${PKGNAMESUFFIX}

WRKSRC=		${WRKDIR}/FVCOM4.0/FVCOM_source
MAKEFILE=	makefile
MAKE_CMD=	gmake
ALL_TARGET=	fvcom

RESTRICTED=	Requires (free) registration

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTFILES})
IGNORE=	may not be redistributed because of licensing reasons.\
	Please register at http://fvcom.smast.umassd.edu/FVCOM/index.html\
	in order to download the source code ${DISTFILES}\
	and place it in ${DISTDIR}/${DIST_SUBDIR}/
.endif

MAKE_JOBS_UNSAFE=	yes

pre-build:
	cp ${FILESDIR}/make.inc ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${MPIPREFIX}bin
	${INSTALL_PROGRAM} ${WRKSRC}/fvcom \
		${STAGEDIR}${PREFIX}/${MPIPREFIX}bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.post.mk>
