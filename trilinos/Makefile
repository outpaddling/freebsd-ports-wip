PORTNAME=	trilinos
PORTVERSION=	10.10.2
CATEGORIES=	wip math
# The correct URL
# MASTER_SITES=	http://trilinos.sandia.gov/download/${PORTNAME}-10.10.html/
# Temporary for development: Circumvents registration requirement
MASTER_SITES=	http://trilinos.sandia.gov/download/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Object-oriented math libraries
WWW=		https://trilinos.sandia.gov/

# Add if building shared libs
USE_LDCONFIG=	${PREFIX}/${PORTNAME}/lib

USE_FORTRAN=	yes
USE_CMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-build

OPTIONS=	TESTING "Build testing suite.  Adds hours to build." off

CMAKE_SOURCE_PATH=	${WRKDIR}/${DISTNAME}
CMAKE_INSTALL_PREFIX=	${PREFIX}/${PORTNAME}
CMAKE_ARGS+= \
	-DCMAKE_BUILD_TYPE=DEBUG \
	-DBUILD_SHARED_LIBS:BOOL=ON \
	-DTrilinos_ENABLE_ALL_PACKAGES:BOOL=ON \
	-DTPL_ENABLE_MPI:BOOL=ON \
	-DMPI_BASE_DIR:PATH=${LOCALBASE}/mpi/openmpi

#	-DCMAKE_VERBOSE_MAKEFILE:BOOL=TRUE \
#	-DTrilinos_VERBOSE_CONFIGURE:BOOL=TRUE

.include <bsd.port.pre.mk>

.if defined(WITH_TESTING)
CMAKE_ARGS+=	-D Trilinos_ENABLE_TESTS:BOOL=ON
.endif

# 4.1G to build with testing, 3G without!
# FreeBSD libm does not yet support long double functions
post-patch:
	${REINPLACE_CMD} -e 's|powl|pow|g' -e 's|tgammal|tgamma|g' \
		${CMAKE_SOURCE_PATH}/packages/intrepid/test/Discretization/Integration/test_*.cpp \
		${CMAKE_SOURCE_PATH}/packages/intrepid/test/Shared/IntrepidBurkardtRules/test_*.cpp

post-install:
	for l in ${PREFIX}/${PORTNAME}/lib/*.so; do \
		${LN} $${l} $${l}.10; \
	done

.include <bsd.port.post.mk>
