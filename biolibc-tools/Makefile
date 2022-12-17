PORTNAME=	biolibc-tools
DISTVERSION=	0.1.4-3
DISTVERSIONSUFFIX=	-gdfa8f2f
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	High-performance bioinformatics tools based on biolibc
WWW=		https://github.com/auerlab/biolibc-tools

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	uthash>0:devel/uthash
LIB_DEPENDS=	libbiolibc.so:wip/biolibc \
		libxtend.so:wip/libxtend \
		libxxhash.so:devel/xxhash

USE_GITHUB=	yes

GH_ACCOUNT=	auerlab

MAKE_ENV=	VERSION=${PORTVERSION}
INSTALL_TARGET=	install-strip

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
