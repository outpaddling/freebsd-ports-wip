# Created by: Jason Bacon <jwb@FreeBSD.org>
# $FreeBSD$
# Note for pkgsrc conversion: Requires zlib

PORTNAME=	kallisto
PORTVERSION=	0.42.4
DISTVERSIONPREFIX=	v
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Quantify abundances of transcripts from RNA-Seq data

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libsz.so:science/szip

USES=		cmake

# FIXME: This should not be necessary
CXXFLAGS+=	-I${LOCALBASE}/include

USE_GITHUB=	yes
GH_ACCOUNT=	pachterlab

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/kallisto-test ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} test ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
