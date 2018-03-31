# $FreeBSD$

PORTNAME=	pbseqan
PORTVERSION=	0.0.0p20171002
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	PacBio patched and stripped down seqan

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_PROJECT=	seqan
GH_TAGNAME=	d01138731be5d54ef4948053493408075f19e0b1

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/PacBio
	cd ${WRKSRC}/include/seqan && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/PacBio/seqan

.include <bsd.port.mk>
