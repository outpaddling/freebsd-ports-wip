# $FreeBSD: head/biology/bedtools/Makefile 467783 2018-04-19 16:44:59Z jwb $

PORTNAME=	bedtools
DISTVERSIONPREFIX=	v
DISTVERSION=	2.27.1
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Toolset for genome set arithmetic such as intersect, union

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake python
USE_GITHUB=	yes
GH_ACCOUNT=	arq5x
GH_PROJECT=	bedtools2

pre-build:
	@${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|@\$$(CXX)|$$(CXX)|g' \
		${WRKSRC}/*/Makefile \
		${WRKSRC}/*/*/Makefile \
		${WRKSRC}/*/*/*/Makefile \
		${WRKSRC}/*/*/*/*/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bedtools

.include <bsd.port.mk>
