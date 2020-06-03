# $FreeBSD$

PORTNAME=	edirect
PORTVERSION=	9.30.20180706
# PORTVERSION=	13.7.20200529
CATEGORIES=	wip biology
MASTER_SITES=	ftp://ftp.ncbi.nlm.nih.gov/entrez/entrezdirect/versions/${PORTVERSION}/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Access to the NCBI's suite of interconnected databases

# Fake, find out and update
LICENSE=	BSD2CLAUSE
#LICENSE_FILE=

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https

USES=		go shebangfix
SHEBANG_FILES=	setup.sh nquire edirect.pl

WRKSRC=		${WRKDIR}/${PORTNAME}

SCRIPTS=	esearch elink efilter efetch rchive xtract edirect-einfo epost

post-patch:
	${MV} ${WRKSRC}/einfo ${WRKSRC}/edirect-einfo
	cd ${WRKSRC} && ${REINPLACE_CMD} \
		-e 's|\`dirname "$$0"\`|${PREFIX}/bin|g' ${SCRIPTS}

do-build:
	(cd ${WRKSRC} && ${SETENV} GOPATH=${WRKSRC} ${FILESDIR}/go-build)
	(cd ${WRKSRC} && ./setup.sh)

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} \
		${SCRIPTS} nquire edirect.pl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/*.FreeBSD ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/edirect-test.sh ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
