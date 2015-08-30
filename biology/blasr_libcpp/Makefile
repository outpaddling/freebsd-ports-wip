# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	blasr_libcpp
PORTVERSION=	2015.08.17
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Library for analyzing PacBio sequences

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libhdf5.so:${PORTSDIR}/science/hdf5

USES=		gmake tar:xz

# Requires 64-bit long
NOT_FOR_ARCHS=	i386 powerpc

MAKEFILE=	makefile

CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# MAKE_JOBS_UNSAFE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/makefile

do-configure:
	cd ${WRKSRC} && ./configure.py --no-pbbam \
		HDF5_INCLUDE=${LOCALBASE}/include HDF5_LIB=${LOCALBASE}/lib

post-configure:
	${REINPLACE_CMD} -e 's|define|undef|' ${WRKSRC}/libconfig.h

do-install:
	for fn in `find ${WRKSRC} -name '*.h' -o -name '*.hpp'`; do \
		dir=`dirname $$fn | cut -d / -f 8-`; \
		${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/$$dir; \
		${INSTALL_DATA} $$fn ${STAGEDIR}${PREFIX}/include/${PORTNAME}/$$dir; \
	done
	for fn in `find ${WRKSRC} -name '*.a'`; do \
		${INSTALL_DATA} $$fn ${STAGEDIR}${PREFIX}/lib; \
	done

.include <bsd.port.mk>
