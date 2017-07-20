# Created by: Jason Wayne Bacon <bacon@sciprog.ceas.uwm.edu>
# $FreeBSD$

PORTNAME=	stringtie
PORTVERSION=	1.3.3b
DISTVERSIONPREFIX=v
CATEGORIES=	wip

MAINTAINER=	bacon@sciprog.ceas.uwm.edu
COMMENT=	Transcript assembly and quantification for RNA-Seq

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	gpertea

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/stringtie

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stringtie ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
