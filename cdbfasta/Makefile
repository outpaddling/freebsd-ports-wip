PORTNAME=	cdbfasta
PORTVERSION=	2023.07.10
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fast indexing and retrieval of FASTA records from flat file databases
WWW=		https://sourceforge.net/projects/cdbfasta/

LICENSE=	ART20

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	gpertea
GH_TAGNAME=	da8f5ba

PLIST_FILES=	bin/cdbfasta bin/cdbyank

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdbfasta ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cdbyank ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
