# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD: ports/math/ufc/Makefile,v 1.5 2013/03/22 23:30:08 svnexp Exp $

PORTNAME=	ufc
PORTVERSION=	${MMVERSION}.0
CATEGORIES=	math python
MASTER_SITES=	http://launchpad.net/${PORTNAME}/${MMVERSION}.x/${PORTVERSION}/+download/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Unified framework for finite element assembly

BUILD_DEPENDS=	swig2.0:${PORTSDIR}/devel/swig20
LIB_DEPENDS=	boost_math_c99:${PORTSDIR}/devel/boost-libs

# LICENSE=	public domain

USES=		cmake
USE_CMAKE=	yes
USE_PYTHON=	-2.7
PYDISTUTILS_PKGNAME=	ufc

CMAKE_ARGS+=	-DUFC_PKGCONFIG_DIR=${PREFIX}/libdata/pkgconfig

FETCH_ARGS=	-F

MMVERSION=	2.2

post-patch:
	${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -i '' -e 's|os.path.join(os.path.sep, "usr")|os.path.normpath("${PREFIX}")|' ${WRKSRC}/src/utils/python/ufc_utils/build.py

.include <bsd.port.mk>
