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

# FIXME: Does not conform to filesystem hierarchy
# FIXME: Should eigenlib be replaced by a math/eigen dep?
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/vcg
	cd ${WRKSRC} && ${COPYTREE_SHARE} "apps eigenlib img vcg wrap" ${STAGEDIR}${PREFIX}/include/vcg
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
