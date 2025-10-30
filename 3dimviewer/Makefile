PORTNAME=	3dimviewer
DISTVERSION=	4.1.3
CATEGORIES=	wip science

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	3D viewer of medical DICOM datasets
WWW=		https://example.com/3dimviewer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# mdstk, wxwidgets
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libosg.so:graphics/osg

USES=		cmake:noninja dos2unix gl

# May be a mirror of bitbucket
USE_GITHUB=	yes
USE_GL=		glew

GH_ACCOUNT=	SindenDev

.include <bsd.port.mk>
