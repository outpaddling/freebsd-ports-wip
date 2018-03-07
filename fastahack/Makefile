# $FreeBSD$

PORTNAME=	fastahack
PORTVERSION=	0.0.0p20160702
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Utilities for indexing and sequence extraction from FASTA files

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TAGNAME=	bbc645f2f7966cb7b44446200c02627c3168b399

INSTALL_TARGET=	install-strip

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
