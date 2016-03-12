# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=		jellyfish
PORTVERSION=		2.2.4
DISTVERSIONPREFIX=	v
CATEGORIES=		biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Fast, memory-efficient counting of k-mers in DNA

LICENSE=	GPLv3

BUILD_DEPENDS+=	yaggo:${PORTSDIR}/devel/yaggo

GNU_CONFIGURE=	yes

USES=		autoreconf compiler:c++11-lib compiler:openmp gmake \
		libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	gmarcais
GH_PROJECT=	Jellyfish

.include <bsd.port.pre.mk>

# SSE code assumes amd64 features
.if ${ARCH} != "amd64"
.if ${OSVERSION} < 1000000
IGNORE=		Multiple code issues on i386 < 10.0-RELEASE
.else
CONFIGURE_ARGS=	--without-sse
.endif
.endif

post-stage:
	${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/* \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.post.mk>
