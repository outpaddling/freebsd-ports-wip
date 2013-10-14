# $FreeBSD: branches/RELENG_9_2_0/math/armadillo/Makefile 314935 2013-03-22 14:54:42Z pawel $

PORTNAME=	armadillo
PORTVERSION=	3.800.1
CATEGORIES=	math
MASTER_SITES=	SF/arma/

MAINTAINER=	giffunip@tutopia.com
COMMENT=	C++ linear algebra library

LICENSE=	MPL

LIB_DEPENDS=	lapack:${PORTSDIR}/math/lapack	\
		boost_date_time:${PORTSDIR}/devel/boost-libs

USES=		cmake
USE_CMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
