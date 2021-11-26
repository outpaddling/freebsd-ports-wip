PORTNAME=	STAR
DISTVERSION=	2.7.9a
CATEGORIES=	wip biology
PKGNAMEPREFIX=	rna-

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Spliced Transcripts Alignment to a Reference

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/STAR-${DISTVERSION}/LICENSE

NOT_FOR_ARCHS=	i386 powerpc
NOT_FOR_ARCHS_REASON=Needs 16+ GiB RAM for typical eukaryotic genome

USES=		compiler:c++11-lang gmake
USE_GITHUB=	yes
GH_ACCOUNT=	alexdobin

WRKSRC_SUBDIR=	source

PLIST_FILES=	bin/STAR

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/STAR ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
