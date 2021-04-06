
PORTNAME=	vcglib
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	wip graphics

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Template library for manipulation of triangle meshes

# Unspecified.  Assuming public domain.
LICENSE=	PD

USE_GITHUB=	yes
GH_ACCOUNT=	cnr-isti-vclab

NO_BUILD=	yes

# FIXME: Does not conform to filesystem hierarchy
# FIXME: Should eigenlib be replaced by a math/eigen dep?
do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/vcg
	cd ${WRKSRC} && ${COPYTREE_SHARE} "apps eigenlib img vcg wrap" ${STAGEDIR}${PREFIX}/include/vcg
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
