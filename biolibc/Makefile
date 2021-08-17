# Created by: J. Bacon <jwb@FreeBSD.org>

PORTNAME=	biolibc
DISTVERSION=	0.1.3-84
DISTVERSIONSUFFIX=	-gc55f0c0
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Low-level high-performance bioinformatics library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so.2:wip/libxtend

USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	auerlab

INSTALL_TARGET=	install-strip

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
