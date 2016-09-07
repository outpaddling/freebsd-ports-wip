# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	unanimity
PORTVERSION=	2016.08.31
CATEGORIES=	biology
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Consensus library and applications

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhts.so:biology/htslib

USES=		cmake python
USE_PYTHON=	distutils

USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	0b166c4ee7cd45f9eb88b7d9284ba299b1c21006

CMAKE_ARGS+=	-DHTSLIB_INCLUDE_DIRS:STRING=${LOCALBASE}/include/htslib \
		-DHTSLIB_LIBRARIES:STRING="-L${LOCALBASE}/lib -lhts" \
		-DPacBioBAM_INCLUDE_DIRS:STRING=${LOCALBASE}/pbbam \
		-DPacBioBAM_LIBRARIES:STRING="-L${LOCALBASE}/lib -lpbbam"

.include <bsd.port.mk>
