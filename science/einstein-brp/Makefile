# Created by: Jason Bacon <bacon@manta.acadix.biz>
# $FreeBSD$

PORTNAME=	einstein-brp
PORTVERSION=	2014.10.27
CATEGORIES=	astro
MASTER_SITES=	http://www.acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	bacon@manta.acadix.biz
COMMENT=

USES=		tar:xz gmake

WRKSRC=		${WRKDIR}/${DISTNAME}/src
ALL_TARGET=	default

# BINUTILS_VERSION=2.22
# GSL_VERSION=1.12
# FFTW_VERSION=3.3.2
# LIBXML_VERSION=2.6.32
# ZLIB_VERSION=1.2.7
# clfft?

LIB_DEPENDS+=	libgsl.so:${PORTSDIR}/math/gsl \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libxml2.so:${PORTSDIR}/textproc/libxml2
		

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
