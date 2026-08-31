PORTNAME=		salmon
DISTVERSIONPREFIX=	v
DISTVERSION=		2.7.0
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Transcript-level quantification of RNA-seq from lightweight alignments
WWW=		https://github.com/COMBINE-lab/salmon

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		armv6 armv7 i386 powerpc powerpcspe
NOT_FOR_ARCHS_REASON=	Requires 64-bit processor

USES=		cargo
USE_GITHUB=	yes

GH_ACCOUNT=	COMBINE-lab

.include <bsd.port.mk>
