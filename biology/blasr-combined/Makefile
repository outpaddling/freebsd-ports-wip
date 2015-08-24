# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

# Note: This port builds a combined blasr + blasr_libcpp
# blasr_libcpp may be separated at some point in the future

PORTNAME=	blasr
PORTVERSION=	2015.08.17
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/
DISTNAME=	${PORTNAME}-combined-${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	PacBio(R) long read aligner

LICENSE=	BSD3CLAUSE

IGNORE=		Use the separate blasr and blasr_libcpp

USES=		gmake tar:xz

LIB_DEPENDS=	libhdf5.so:${PORTSDIR}/science/hdf5
BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash

# Requires 64-bit long
NOT_FOR_ARCHS=	i386

MAKEFILE=	makefile
CONFIGURE_ENV+=	NOPBBAM=1

CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_JOBS_UNSAFE=	yes

post-patch:
	${REINPLACE_CMD} \
		-e 's|/bin/bash|${LOCALBASE}/bin/bash|g' \
		-e 's|-ldl||g' \
		${WRKSRC}/makefile ${WRKSRC}/libcpp/makefile

do-configure:
	cd ${WRKSRC}/libcpp && ./configure.py --no-pbbam \
		NOPBBAM=1 HDF5_INCLUDE=${LOCALBASE}/include HDF5_LIB=${LOCALBASE}/lib
	cd ${WRKSRC} && ./configure.py --no-pbbam \
		NOPBBAM=1 HDF5_INCLUDE=${LOCALBASE}/include HDF5_LIB=${LOCALBASE}/lib

post-configure:
	${REINPLACE_CMD} -e 's|define|undef|' ${WRKSRC}/libcpp/pbdata/libconfig.h
	${REINPLACE_CMD} \
		-e 's|-lhdf5$$|-lhdf5 -lsz|g' \
		-e 's|-ldl||g' \
		${WRKSRC}/makefile ${WRKSRC}/libcpp/makefile ${WRKSRC}/defines.mk

do-build:
	cd ${WRKSRC} && ${GMAKE} build-submodule
	cd ${WRKSRC} && ${GMAKE}

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
	${INSTALL_DATA} \
		${WRKSRC}/libcpp/alignment/libblasr.so \
		${WRKSRC}/libcpp/hdf/libpbihdf.so \
		${WRKSRC}/libcpp/pbdata/libpbdata.so \
		${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
