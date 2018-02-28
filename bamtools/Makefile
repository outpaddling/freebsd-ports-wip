# $FreeBSD$

PORTNAME=	bamtools
PORTVERSION=	2.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	wip biology

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	API and toolkit for handling BAM files

LICENSE=	MIT

USES=		cmake:outsource
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	pezmaster31

CMAKE_ARGS+=	-DLIB_DIR=${PREFIX}/lib

.include <bsd.port.pre.mk>

# Just for speed: Recent compilers have better optimizers
USES=		compiler:c++11-lang

post-patch:
	${REINPLACE_CMD} -e 's|lib/bamtools|lib|g' \
		${WRKSRC}/src/api/CMakeLists.txt

.include <bsd.port.post.mk>
