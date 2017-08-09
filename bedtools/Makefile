# Created by: Scott Cheloha <scottcheloha@gmail.com>
# $FreeBSD: head/biology/bedtools/Makefile 441847 2017-05-27 15:07:11Z linimon $

PORTNAME=	bedtools
PORTVERSION=	2.26.0
DISTVERSIONPREFIX=	v
CATEGORIES=	wip biology
MASTER_SITES=	GITHUB

MAINTAINER=	scottcheloha@gmail.com
COMMENT=	Toolset for genome arithmetic

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv6=		fails to compile: implicit instantiation of undefined template __static_assert_test<false>

USES=		gmake python
USE_GITHUB=	yes
GH_ACCOUNT=	arq5x
GH_PROJECT=	bedtools2

WRKSRC=		${WRKDIR}/${PORTNAME}2-${PORTVERSION}

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
