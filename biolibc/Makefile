PORTNAME=	biolibc
DISTVERSION=	0.2.0-31
DISTVERSIONSUFFIX=	-gee7e2b1
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Low-level high-performance bioinformatics library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:wip/libxtend

USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	auerlab

INSTALL_TARGET=	install-strip

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
