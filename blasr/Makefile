PORTNAME=	blasr
DISTVERSION=	g20180411
#DISTNAME=smrtanalysis
#DISTVERSION=	4.0.0
#DISTVERSIONSUFFIX=	-121-geab53fd
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	PacBio(R) long read aligner
WWW=		https://github.com/PacificBiosciences/blasr

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libhdf5-18.so:science/hdf5-18 \
		libsz.so:science/szip \
		libblasr.so:wip/blasr_libcpp \
		libhts.so:biology/htslib \
		libcurl.so:ftp/curl

USES=		gmake tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	eab53fd

MAKEFILE=	makefile
MAKE_ENV=	GH_TAGNAME=${GH_TAGNAME}

do-configure:
	cd ${WRKSRC} && ./configure.py --shared \
		HDF5_INCLUDE=${LOCALBASE}/include/hdf5-18 \
		HDF5_LIB=${LOCALBASE}/lib \
		HDF5_LIBFLAGS="-lhdf5-18_cpp -lhdf5-18" \
		LIBPBDATA_INC=${LOCALBASE}/include/blasr_libcpp/pbdata \
		LIBPBDATA_LIB=${LOCALBASE}/lib \
		LIBPBIHDF_INC=${LOCALBASE}/include/blasr_libcpp/hdf \
		LIBPBIHDF_LIB=${LOCALBASE}/lib \
		LIBBLASR_INC=${LOCALBASE}/include/blasr_libcpp/alignment \
		LIBBLASR_LIB=${LOCALBASE}/lib \
		PBBAM_INC=${LOCALBASE}/include \
		PBBAM_LIB=${LOCALBASE}/lib \
		HTSLIB_LIBS="-lhts -llzma -lcurl" \
		DL_LIBFLAGS=""

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
