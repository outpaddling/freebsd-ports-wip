# $FreeBSD$

PORTNAME=	hisat2
# DISTVERSION=	2.1.0p20180625
DISTVERSION=	2.1.0-20
DISTVERSIONSUFFIX=	-g5622808
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Alignment program for mapping next-generation sequencing reads

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	infphilo
# GH_TAGNAME=	f34a56512ced8d84e035dbfb4312513bf36e32a2

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
