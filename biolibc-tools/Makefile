# Created by: J. Bacon <jwb@FreeBSD.org>

PORTNAME=	biolibc-tools
DISTVERSION=	0.1.0-4
DISTVERSIONSUFFIX=	-ga59e9ff
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	High-performance bioinformatics tools based on biolibc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbiolibc.so:wip/biolibc \
		libxtend.so:wip/libxtend

USE_GITHUB=	yes

GH_ACCOUNT=	auerlab

INSTALL_TARGET=	install-strip

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
