# Created by: Jason Bacon <jwb@FreeBSD.org>
# $FreeBSD: head/math/ufc/Makefile 344599 2014-02-16 16:16:16Z miwi $

PORTNAME=	ufc
PORTVERSION=	${MMVERSION}.0
PORTREVISION=	1
CATEGORIES=	wip math python
MASTER_SITES=	http://launchpad.net/${PORTNAME}/${MMVERSION}.x/${PORTVERSION}/+download/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Unified framework for finite element assembly

BUILD_DEPENDS=	swig2.0:devel/swig20
LIB_DEPENDS=	libboost_math_c99.so:devel/boost-libs

# LICENSE=	public domain

USES=		cmake python:2
PYDISTUTILS_PKGNAME=	ufc

CMAKE_ARGS+=	-DUFC_PKGCONFIG_DIR=${PREFIX}/libdata/pkgconfig

MMVERSION=	2.2

post-patch:
	${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -i '' -e 's|os.path.join(os.path.sep, "usr")|os.path.normpath("${PREFIX}")|' ${WRKSRC}/src/utils/python/ufc_utils/build.py

.include <bsd.port.mk>
