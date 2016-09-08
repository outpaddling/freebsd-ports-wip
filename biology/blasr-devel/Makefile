# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	blasr
PORTVERSION=	2016.09.07
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	PacBio(R) long read aligner

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libsz.so:science/szip
BUILD_DEPENDS=	blasr_libcpp==${PORTVERSION}:/usr/wip/biology/blasr_libcpp-devel

USES=		gmake tar:xz

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

MAKE_JOBS_UNSAFE=	yes

post-patch:
	${REINPLACE_CMD} \
		-e 's|/bin/bash|${LOCALBASE}/bin/bash|g' \
		-e 's|-ldl||g' \
		${WRKSRC}/makefile

do-configure:
	cd ${WRKSRC} && ./configure.py --no-pbbam \
		NOPBBAM=1 HDF5_INCLUDE=${LOCALBASE}/include HDF5_LIB=${LOCALBASE}/lib

post-configure:
	${REINPLACE_CMD} \
		-e 's|-lhdf5$$|-lhdf5 -lsz|g' \
		-e 's|-ldl||g' \
		${WRKSRC}/makefile ${WRKSRC}/defines.mk

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
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
