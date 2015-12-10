# Created by: Dan Siercks
# $FreeBSD$

PORTNAME=	bamtools
PORTVERSION=	2.4.0
CATEGORIES=	biology

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	API and toolkit for handling BAM files

LICENSE=	MIT

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		cmake:outsource
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	pezmaster31
GH_TAGNAME=	v${PORTVERSION}

CMAKE_ARGS+=	-DLIB_DIR=${PREFIX}/lib

.include <bsd.port.pre.mk>

# Just for speed: Recent compilers have better optimizers
USES=		compiler:c++11-lang

post-patch:
	${REINPLACE_CMD} -e 's|lib/bamtools|lib|g' \
		work/bamtools-2.4.0/src/api/CMakeLists.txt

.include <bsd.port.post.mk>
