PORTNAME=	angora
PORTVERSION=	0.18.5
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	wip science math
MASTER_SITES=	http://angorafdtd.org/angora/
#MASTER_SITE_SUBDIR=
#PKGNAMEPREFIX=
#PKGNAMESUFFIX=
#DISTNAME=
#EXTRACT_SUFX=
#DISTFILES=
#DIST_SUBDIR=	${PORTNAME}
#EXTRACT_ONLY=

MAINTAINER=	jwb@FreeBSD.org
COMMENT=

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

LIB_DEPENDS=	blitz:math/blitz++ \
		hdf5:science/hdf5 \
		config:devel/libconfig \
		argp:devel/argp-standalone

CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -largp

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
