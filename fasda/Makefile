PORTNAME=	fasda
DISTVERSION=	0.1.1-18
DISTVERSIONSUFFIX=	-g4dd6c85
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fast and simple differential analysis
WWW=		https://github.com/auerlab/fasda

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# Requires libxtend 0.1.6-22
LIB_DEPENDS=	libxtend.so:wip/libxtend libbiolibc.so:wip/biolibc

USES=		localbase
USE_GITHUB=	yes

GH_ACCOUNT=	auerlab

MAKE_ENV=	VERSION=${PORTVERSION}
INSTALL_TARGET=	install-strip

pre-build:
	cd ${WRKSRC} && make depend LOCALBASE=${LOCALBASE}

.include <bsd.port.mk>
