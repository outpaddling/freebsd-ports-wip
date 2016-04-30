# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$
# Note for pkgsrc conversion: Requires zlib

PORTNAME=	kallisto
PORTVERSION=	0.42.4
CATEGORIES=	biology
DISTVERSIONPREFIX=	v

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Quantify abundances of transcripts from RNA-Seq data

LIB_DEPENDS=	libhdf5.so:science/hdf5

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	pachterlab

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/kallisto-test ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} test ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
