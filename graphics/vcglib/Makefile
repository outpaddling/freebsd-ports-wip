# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	vcglib
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Template library for manipulation of triangle meshes

# Unspecified.  Assuming public domain.
LICENSE=	PD

USE_GITHUB=	yes
GH_ACCOUNT=	cnr-isti-vclab

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/vcg
	cd ${WRKSRC}/vcg && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/vcg
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "apps img wrap" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
