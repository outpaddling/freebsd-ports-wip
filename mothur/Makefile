PORTNAME=	mothur
DISTVERSIONPREFIX=	v
DISTVERSION=	1.45.2
CATEGORIES=	wip biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software for bioinformatics of the microbial ecology community
WWW=		https://www.mothur.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang gmake localbase readline
USE_GITHUB=	yes
ALL_TARGET=	${PORTNAME}

BINARY_ALIAS=	g++=${CXX}

EXES=		${PORTNAME} uchime

PLIST_FILES=	${EXES:S/^/bin\//}

do-install: # https://github.com/mothur/mothur/issues/615
.for e in ${EXES}
	${INSTALL_PROGRAM} ${WRKSRC}/${e} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
