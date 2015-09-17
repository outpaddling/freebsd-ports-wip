# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	cd-hit
PORTVERSION=	4.6.4
CATEGORIES=	biology
MASTER_SITES=	https://github.com/weizhongli/cdhit/releases/download/V${PORTVERSION}/
DISTNAME=	${PORTNAME}-v${PORTVERSION}-2015-0603

MAINTAINER=	jwbacon@tds.net
COMMENT=	Clustering and comparing protein or nucleotide sequences

LICENSE=	GPLv2

USES=		gmake shebangfix
# Only for OpenMP
USE_GCC=	yes
SHEBANG_FILES=	${WRKSRC}/*.pl

MAKEFILE=	makefile
MAKE_FLAGS=	openmp=yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's|g++|${CXX}|g' \
		-e 's|\$$(PREFIX)|$${DESTDIR}$${PREFIX}/bin|g' \
		${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} \
		-e 's|/bin/bash|${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/*.pl

post-stage:
	@cd ${STAGEDIR}${PREFIX}/bin && \
		${STRIP_CMD} cd-hit cd-hit-2d cd-hit-454 \
		cd-hit-div cd-hit-est cd-hit-est-2d

.include <bsd.port.mk>
