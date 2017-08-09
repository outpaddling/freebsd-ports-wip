# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	multichoose
PORTVERSION=	2015.11.22
CATEGORIES=	wip math

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Generate multiset combinations (n multichoose k)

LICENSE=	MIT

USES=		python shebangfix
SHEBANG_FILES=	*.py

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	a35c94abd1b312fdcc10455f90b6e527c271bb35

WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
