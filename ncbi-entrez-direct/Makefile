PORTNAME=	ncbi-entrez-direct
DISTVERSION=	14.9.20210414
CATEGORIES=	wip biology
MASTER_SITES=	ftp://ftp.ncbi.nlm.nih.gov/entrez/entrezdirect/versions/${PORTVERSION}/
DISTNAME=	edirect

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Access to the NCBI's suite of interconnected databases

LICENSE=	PD	# Unspecified

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-XML-Simple>=0:textproc/p5-XML-Simple

USES=		go:modules shebangfix
SHEBANG_FILES=	setup.sh nquire edirect.pl word-at-a-time

WRKSRC=		${WRKDIR}/${DISTNAME}

PSCRIPTS=	esearch efetch epost einfo efilter elink esummary nquire
SCRIPTS=	esearch efetch epost einfo efilter elink esummary xtract \
		sort-uniq-count-rank word-at-a-time nquire
LIBEXEC=	rchive ecommon.sh nquire edirect.pl join-into-groups-of
LIBEXEC_DIR=	${PREFIX}/libexec/edirect

pre-configure:
	(cd ${WRKSRC} && ${REINPLACE_CMD} \
		-e 's|$$PATH:$$pth|$$PATH:${LIBEXEC_DIR}|g' \
		-e 's|"$$pth"|${LIBEXEC_DIR}|g' \
		${PSCRIPTS})

do-build:
	(cd ${WRKSRC}/cmd && ${SETENV} GOPATH=${WRKSRC} ${FILESDIR}/go-build)
	(cd ${WRKSRC} && ./setup.sh)

do-install:
	${MKDIR} ${STAGEDIR}${LIBEXEC_DIR}
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${SCRIPTS} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${LIBEXEC} \
		${STAGEDIR}${PREFIX}/libexec/edirect
	${INSTALL_PROGRAM} ${WRKSRC}/cmd/*.FreeBSD ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/edirect-test.sh ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
