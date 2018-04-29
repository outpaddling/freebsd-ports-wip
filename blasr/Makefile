# $FreeBSD$

PORTNAME=	blasr
DISTVERSION=	g20180411
#DISTNAME=smrtanalysis
#DISTVERSION=	4.0.0
#DISTVERSIONSUFFIX=	-121-geab53fd
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	PacBio(R) long read aligner

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libsz.so:science/szip \
		libblasr.so:wip/blasr_libcpp

USES=		gmake tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	eab53fd220a05dfd7290962360a6ccce55be9c7c

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
