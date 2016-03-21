# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$
# Note for pkgsrc conversion: Requires zlib

PORTNAME=	kallisto
PORTVERSION=	0.42.4
CATEGORIES=	biology
DISTVERSIONPREFIX=	v

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Quantify abundances of transcripts from RNA-Seq data

LIB_DEPENDS=	libhdf5.so:${PORTSDIR}/science/hdf5

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	pachterlab

PLIST_FILES=	bin/kallisto

.include <bsd.port.mk>
