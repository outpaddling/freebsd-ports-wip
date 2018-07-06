# $FreeBSD$

PORTNAME=	edirect
PORTVERSION=	0.0.0p20180706
CATEGORIES=	wip biology
MASTER_SITES=	ftp://ftp.ncbi.nlm.nih.gov/entrez/entrezdirect/
DISTNAME=	${PORTNAME}

MAINTAINER=	bacon@imacbsd.acadix.biz
COMMENT=	Access to the NCBI's suite of interconnected databases

# Fake, find out and update
LICENSE=	BSD2CLAUSE
#LICENSE_FILE=

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww

USES=		shebangfix
SHEBANG_FILES=	setup.sh nquire edirect.pl

SCRIPTS=	esearch elink efilter efetch xtract edirect-einfo epost

post-patch:
	${MV} ${WRKSRC}/einfo ${WRKSRC}/edirect-einfo
	cd ${WRKSRC} && ${REINPLACE_CMD} \
		-e 's|\`dirname "$$0"\`|${PREFIX}/bin|g' ${SCRIPTS}

do-build:
	cd ${WRKSRC} && ./setup.sh

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} \
		${SCRIPTS} nquire edirect.pl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
