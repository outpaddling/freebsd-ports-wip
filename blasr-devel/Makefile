# $FreeBSD$

PORTNAME=	blasr
PORTVERSION=	2016.09.07
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	PacBio(R) long read aligner

LICENSE=	BSD3CLAUSE

# FIXME: Add pbbam
LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libsz.so:science/szip \
		libhts.so:biology/htslib \
		libconfig.so:devel/libconfig \
		libboost-regex.so:devel/boost-libs
BUILD_DEPENDS=	blasr_libcpp==${PORTVERSION}:wip/blasr_libcpp-devel

USES=		cmake gmake ssl

USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	0061445b1387c545780679776d3d483a30d4332b

MAKEFILE=	makefile

CXXFLAGS+=	-I${LOCALBASE}/include/blasr_libcpp \
		-I${LOCALBASE}/include/blasr_libcpp/hdf \
		-I${LOCALBASE}/include/blasr_libcpp/pbdata \
		-I${LOCALBASE}/include/blasr_libcpp/alignment \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

#MAKE_JOBS_UNSAFE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

CMAKE_ARGS= \
	-DPBDATA_ROOT_DIR:STRING=${PREFIX}/include/blasr_libcpp \
	-DPacBioBAM_INCLUDE_DIRS:STRING=${LOCALBASE}/include/pbbam \
	-DPacBioBAM_LIBRARIES:STRING="-L${LOCALBASE}/lib -lpbbam" \
	-DHTSLIB_INCLUDE_DIRS:STRING=${LOCALBASE}/include/htslib \
	-DHTSLIB_LIBRARIES:STRING="-L${LOCALBASE}/lib -lhts" \
	-DPBDATA_INCLUDE_DIRS:STRING=${LOCALBASE}/include/blasr_libcpp/pbdata \
	-DPBDATA_LIBRARIES:STRING="-L${LOCALBASE}/lib -lpbdata" \
	-DPBIHDF_INCLUDE_DIRS:STRING=${LOCALBASE}/include/blasr_libcpp/hdf \
	-DPBIHDF_LIBRARIES:STRING="-L${LOCALBASE}/lib -lpbihdf" \
	-DBLASR_INCLUDE_DIRS:STRING=${LOCALBASE}/include/blasr_libcpp/alignment \
	-DBLASR_LIBRARIES:STRING="-L${LOCALBASE}/lib -lblasr" \
	-DHDF5_INCLUDE_DIRS:STRING=${LOCALBASE}/include \
	-DHDF5_CPP_LIBRARIES:STRING="-L${LOCALBASE}/lib -lhdf5_cpp" \
	-DHDF5_LIBRARIES:STRING="-L${LOCALBASE}/lib -lhdf5" \
	..

# FIXME: PBBAM is available as a port now
do-configure:
	cd ${WRKSRC} && ./configure.py --no-pbbam \
		NOPBBAM=1 HDF5_INCLUDE=${LOCALBASE}/include HDF5_LIB=${LOCALBASE}/lib

post-configure:
	${REINPLACE_CMD} \
		-e 's|-lhdf5$$|-lhdf5 -lsz|g' \
		-e 's|-ldl||g' \
		${WRKSRC}/makefile ${WRKSRC}/defines.mk

post-build:
	${MKDIR} ${WRKSRC}/utils/bax2bam/build
	cd ${WRKSRC}/utils/bax2bam/build && \
		cmake ${CMAKE_ARGS} -DBax2BAM_build_tests:BOOL=OFF && \
		${MAKE} VERBOSE=1

# bam2bax seems to have code issues
#	${MKDIR} ${WRKSRC}/utils/bam2bax/build
#	cd ${WRKSRC}/utils/bam2bax/build && \
#		cmake ${CMAKE_ARGS} -DBam2Bax_build_tests:BOOL=OFF && \
#		${MAKE} VERBOSE=1

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/blasr \
		${WRKSRC}/utils/loadPulses \
		${WRKSRC}/utils/pls2fasta \
		${WRKSRC}/utils/samFilter \
		${WRKSRC}/utils/samtoh5 \
		${WRKSRC}/utils/samtom4 \
		${WRKSRC}/utils/sawriter \
		${WRKSRC}/utils/sdpMatcher \
		${WRKSRC}/utils/toAfg \
		${WRKSRC}/utils/bax2bam/bin/* \
		${STAGEDIR}${PREFIX}/bin

#		${WRKSRC}/utils/bam2bax/bin/* \

.include <bsd.port.mk>
