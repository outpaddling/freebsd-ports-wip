# Created by: Jason Bacon <bacon@imacbsd.acadix.biz>
# $FreeBSD$

PORTNAME=	edirect
PORTVERSION=	2017.06.15
CATEGORIES=	wip biology
MASTER_SITES=	ftp://ftp.ncbi.nlm.nih.gov/entrez/entrezdirect/
DISTNAME=	${PORTNAME}

MAINTAINER=	bacon@imacbsd.acadix.biz
COMMENT=	Access to the NCBI's suite of interconnected databases

# Fake, find out and update
LICENSE=	BSD2CLAUSE
#LICENSE_FILE=

BUILD_DEPENDS+=	bash:shells/bash

USES=		shebangfix zip
SHEBANG_FILES=	setup.sh nquire edirect.pl xtract.pl

SCRIPTS=	esearch elink efilter efetch xtract edirect-einfo epost

post-patch:
	${MV} ${WRKSRC}/einfo ${WRKSRC}/edirect-einfo
	cd ${WRKSRC} && ${REINPLACE_CMD} \
		-e 's|\`dirname "$$0"\`|${PREFIX}/bin|g' ${SCRIPTS}

do-build:
	cd ${WRKSRC} && ./setup.sh

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} \
		${SCRIPTS} nquire edirect.pl xtract.pl \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
