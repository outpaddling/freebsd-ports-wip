# Created by: Jason Bacon

PORTNAME=		ncbi-entrez-direct
DISTVERSION=		14.9.20210414
CATEGORIES=		wip biology
MASTER_SITES=		ftp://ftp.ncbi.nlm.nih.gov/entrez/entrezdirect/versions/${PORTVERSION}/
DISTFILES=		edirect.tar.gz
DIST_SUBDIR=		edirect-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Access to the NCBI's suite of interconnected databases

LICENSE=	PD	# Unspecified

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-XML-Simple>=0:textproc/p5-XML-Simple

USES=		go:modules perl5 shebangfix
USE_GITHUB=	nodefault

GHSD=		vendor/github.com
GLSD=		vendor/golang.org
GH_TUPLE=	fatih:color:v1.10.0:a/${GHSD}/fatih/color \
		surgebase:porter2:56e4718818e8:b/${GHSD}/surgebase/porter2 \
		gedex:inflector:16278e9db813:c/${GHSD}/gedex/inflector \
		klauspost:cpuid:v1.3.1:d/${GHSD}/klauspost/cpuid \
		pbnjay:memory:b12e5d931931:e/${GHSD}/pbnjay/memory \
		mattn:go-colorable:v0.1.8:f/${GHSD}/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:g/${GHSD}/mattn/go-isatty \
		fiam:gounidecode:8deddbd03fec:h/${GHSD}/fiam/gounidecode \
		golang:text:v0.3.5:i/${GLSD}/x/text \
		golang:sys:d5e6a3e2c0ae:j/${GLSD}/x/sys

SHEBANG_FILES=	setup.sh nquire edirect.pl word-at-a-time accn-at-a-time \
		amino-acid-composition between-two-genes exclude-uid-lists \
		filter-stop-words intersect-uid-lists phrase-search \
		skip-if-file-exists theme-aliases

PSCRIPTS=	efetch efilter einfo elink epost esearch esummary nquire
SCRIPTS=	accn-at-a-time amino-acid-composition archive-pubmed \
		between-two-genes download-ncbi-data download-pubmed \
		download-sequence efetch efilter einfo elink epost \
		esample esearch esummary exclude-uid-lists expand-current \
		fetch-pubmed filter-stop-words gbf2xml index-extras \
		index-pubmed intersect-uid-lists join-into-groups-of \
		nquire phrase-search pm-collect pm-index pm-invert pm-merge \
		pm-prepare pm-promote pm-refresh pm-stash rchive \
		reorder-columns run-ncbi-converter skip-if-file-exists \
		sort-uniq-count sort-uniq-count-rank stream-pubmed \
		theme-aliases transmute word-at-a-time xml2tbl xtract xy-plot \
		ecommon.sh hlp-xtract.txt transmute xml2json xtract

LIBEXEC_DIR=	${PREFIX}/libexec/edirect

post-extract:
	${MV} ${WRKDIR}/edirect/* ${WRKSRC}
	${RMDIR} ${WRKDIR}/edirect
	${MV} ${WRKSRC}/vendor ${WRKSRC}/cmd

pre-configure:
	cd ${WRKSRC} && ${REINPLACE_CMD} \
		-e 's|$$PATH:$$pth|$$PATH:${LIBEXEC_DIR}|g' \
		-e 's|"$$pth"|${LIBEXEC_DIR}|g' \
		${PSCRIPTS}

do-build:
	${CP} ${FILESDIR}/modules.txt ${FILESDIR}/modules.txt ${WRKSRC}/cmd/vendor
	${CP} -R ${WRKSRC}/eutils ${WRKSRC}/cmd/vendor
	cd ${WRKSRC}/cmd && ${FILESDIR}/go-build
	cd ${WRKSRC} && ./setup.sh

do-install:
	${MKDIR} ${STAGEDIR}${LIBEXEC_DIR}
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${SCRIPTS} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${STAGEDIR}${LIBEXEC_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/cmd/*.FreeBSD ${STAGEDIR}${LIBEXEC_DIR}
	${INSTALL_SCRIPT} ${FILESDIR}/edirect-test.sh ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
