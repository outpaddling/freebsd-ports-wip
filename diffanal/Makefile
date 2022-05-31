PORTNAME=	diffanal
DISTVERSION=	0.1.0-17
DISTVERSIONSUFFIX=	-g6c0e4c6
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fast, simple differential analysis

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:wip/libxtend libbiolibc.so:wip/biolibc

USES=		localbase
USE_GITHUB=	yes

GH_ACCOUNT=	auerlab

pre-build:
	cd ${WRKSRC} && make depend LOCALBASE=${LOCALBASE}

.include <bsd.port.mk>
