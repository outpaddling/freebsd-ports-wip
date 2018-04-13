# $FreeBSD$

PORTNAME=		multichoose
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.3-2
DISTVERSIONSUFFIX=	-g3b8d14e
CATEGORIES=		wip math

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Generate multiset combinations (n multichoose k)

LICENSE=	MIT

USES=		python shebangfix
SHEBANG_FILES=	*.py

USE_GITHUB=	yes
GH_ACCOUNT=	ekg

INSTALL_TARGET=	install-strip

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
