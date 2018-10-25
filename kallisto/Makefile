# $FreeBSD: head/biology/kallisto/Makefile 479046 2018-09-05 22:05:23Z sunpoet $

PORTNAME=	kallisto
DISTVERSIONPREFIX=	v
DISTVERSION=	0.44.0
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Quantify abundances of transcripts from RNA-Seq data

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libsz.so:science/szip \
		libhts.so:biology/htslib

USES=		cmake:noninja compiler:c++11-lang
USE_GITHUB=	yes

GH_ACCOUNT=	pachterlab

SUB_FILES=	kallisto-test

PORTEXAMPLES=	*
PLIST_FILES=	bin/kallisto
EXAMPLES_PLIST_FILES=	bin/kallisto-test

OPTIONS_DEFINE=	EXAMPLES
LDFLAGS+=	-L${LOCALBASE}/lib

post-install-EXAMPLES-on:
	${INSTALL_SCRIPT} ${WRKDIR}/kallisto-test ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/test && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
