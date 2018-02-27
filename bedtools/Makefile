# Created by: Scott Cheloha <scottcheloha@gmail.com>
# $FreeBSD: head/biology/bedtools/Makefile 456976 2017-12-22 12:27:14Z amdmi3 $

PORTNAME=	bedtools
PORTVERSION=	2.27.1
DISTVERSIONPREFIX=	v
CATEGORIES=	wip biology
MASTER_SITES=	GITHUB

MAINTAINER=	scottcheloha@gmail.com
COMMENT=	Toolset for genome arithmetic

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake python
USE_GITHUB=	yes
GH_ACCOUNT=	arq5x
GH_PROJECT=	bedtools2

post-patch:
	@${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
