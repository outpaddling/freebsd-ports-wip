# $FreeBSD$

PORTNAME=	uchime
PORTVERSION=	4.2.40
CATEGORIES=	wip biology
MASTER_SITES=	http://drive5.com/uchime/
DISTNAME=	uchime4.2.40_src

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Algorithm for detecting chimeric sequences

LICENSE=	PD

USES=		shebangfix
SHEBANG_FILES=	mk

ALL_TARGET=	uchime

PLIST_FILES=	bin/uchime

post-patch:
	${REINPLACE_CMD} -e 's|g++|${CXX}|g' ${WRKSRC}/mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uchime ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
