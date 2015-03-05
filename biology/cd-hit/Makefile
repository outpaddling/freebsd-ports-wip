# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	cd-hit
PORTVERSION=	4.6.1
CATEGORIES=	biology
MASTER_SITES=	http://cdhit.googlecode.com/files/
DISTNAME=	cd-hit-v4.6.1-2012-08-27

MAINTAINER=	jwbacon@tds.net
COMMENT=	Clustering and comparing protein or nucleotide sequences

LICENSE=	GPLv2

USES=		gmake shebangfix tar:tgz
SHEBANG_FILES=	${WRKSRC}/*.pl

post-patch:
	@${REINPLACE_CMD} \
		-e 's|g++|${CXX}|g' \
		-e 's|$$\(PREFIX\)|$${DESTDIR}$${PREFIX}/bin|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} \
		-e 's|/bin/bash|${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/*.pl

.include <bsd.port.mk>
