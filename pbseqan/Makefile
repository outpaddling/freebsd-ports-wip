# Created by: Jason Bacon <jwb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pbseqan
PORTVERSION=	2016.09.13
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	PacBio patched and stripped down seqan

LICENSE=        BSD3CLAUSE
LICENSE_FILE=   ${WRKSRC}/LICENSE

USES=		compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_PROJECT=	seqan
GH_TAGNAME=	a1fa79fd98923d2a017a792082e2e1252d05e9e3

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/PacBio
	cd ${WRKSRC}/include/seqan && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/PacBio/seqan

.include <bsd.port.mk>
