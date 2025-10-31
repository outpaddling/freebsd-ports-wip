PORTNAME=	3d-slicer
DISTVERSIONPREFIX=	v
DISTVERSION=	5.8.1
CATEGORIES=	wip science

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	
WWW=		https://github.com/Slicer/Slicer

# FIXME: Check extensions
LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		cmake qt:5
USE_GITHUB=	yes
USE_QT=		buildtools:build core gui multimedia widgets script svg uitools:build webengine x11extras xml

GH_ACCOUNT=	Slicer
GH_PROJECT=	Slicer

.include <bsd.port.mk>
