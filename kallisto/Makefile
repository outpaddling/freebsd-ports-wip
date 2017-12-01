# $FreeBSD$

PORTNAME=	kallisto
DISTVERSIONPREFIX=	v
DISTVERSION=	0.43.1
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Quantify abundances of transcripts from RNA-Seq data

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libsz.so:science/szip

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	pachterlab

SUB_FILES=	kallisto-test

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${INSTALL_SCRIPT} ${WRKDIR}/kallisto-test ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/test && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
