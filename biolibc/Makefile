# Created by: J. Bacon <jwb@FreeBSD.org>

PORTNAME=	biolibc
DISTVERSION=	0.1.1-33
DISTVERSIONSUFFIX=	-gd6a6cf4
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Low-level high-performance bioinformatics library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:wip/libxtend

USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
