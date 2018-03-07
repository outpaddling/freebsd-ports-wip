# $FreeBSD$

PORTNAME=	multichoose
PORTVERSION=	1.0.3.p2015.11.17
CATEGORIES=	wip math

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Generate multiset combinations (n multichoose k)

LICENSE=	MIT

USES=		python shebangfix
SHEBANG_FILES=	*.py

USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TAGNAME=	3b8d14e616c719de88261614f0e78195d8ed49e9

INSTALL_TARGET=	install-strip

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
