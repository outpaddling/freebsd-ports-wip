# $FreeBSD$

PORTNAME=	edirect
PORTVERSION=	14.8.20210329
CATEGORIES=	wip biology
MASTER_SITES=	ftp://ftp.ncbi.nlm.nih.gov/entrez/entrezdirect/versions/${PORTVERSION}/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Access to the NCBI's suite of interconnected databases

# Actually unspecified
LICENSE=	MPL20

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-XML-Simple>=0:textproc/p5-XML-Simple

USES=		go shebangfix
SHEBANG_FILES=	setup.sh nquire edirect.pl

WRKSRC=		${WRKDIR}/${PORTNAME}

SCRIPTS=	esearch elink efilter efetch rchive xtract einfo epost

do-build:
	(cd ${WRKSRC}/cmd && ${SETENV} GOPATH=${WRKSRC} ${FILESDIR}/go-build)
	(cd ${WRKSRC} && ./setup.sh)

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} \
		${SCRIPTS} nquire edirect.pl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cmd/*.FreeBSD ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/edirect-test.sh ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
