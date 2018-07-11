# $FreeBSD$

PORTNAME=	edirect
PORTVERSION=	9.30.20180706
CATEGORIES=	wip biology
MASTER_SITES=	ftp://ftp.ncbi.nlm.nih.gov/entrez/entrezdirect/versions/${PORTVERSION}/
DISTNAME=	${PORTNAME}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Access to the NCBI's suite of interconnected databases

# Fake, find out and update
LICENSE=	BSD2CLAUSE
#LICENSE_FILE=

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww

# FIXME: Using Linux binaries is a hack until I learn how to
# Use go properly in a port
# Build rchive and xtract from go sources instead of using Linux binaries
# USES=		go
USES=		linux shebangfix
SHEBANG_FILES=	setup.sh nquire edirect.pl

SCRIPTS=	esearch elink efilter efetch rchive xtract edirect-einfo epost

post-patch:
	${MV} ${WRKSRC}/einfo ${WRKSRC}/edirect-einfo
	cd ${WRKSRC} && ${REINPLACE_CMD} \
		-e 's|\`dirname "$$0"\`|${PREFIX}/bin|g' ${SCRIPTS}

do-build:
	cd ${WRKSRC} && ./setup.sh

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} \
		${SCRIPTS} nquire edirect.pl ${STAGEDIR}${PREFIX}/bin
	${BRANDELF} -t linux ${WRKSRC}/*.Linux
	${INSTALL_PROGRAM} ${WRKSRC}/*.Linux ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
