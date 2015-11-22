# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	blasr
PORTVERSION=	2015.08.17
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	PacBio(R) long read aligner

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libhdf5.so:${PORTSDIR}/science/hdf5 \
		libsz.so:${PORTSDIR}/science/szip
BUILD_DEPENDS=	${LOCALBASE}/lib/libblasr.a:/usr/wip/biology/blasr_libcpp

USES=		gmake tar:xz

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
