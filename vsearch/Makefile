# $FreeBSD$

PORTNAME=	vsearch
PORTVERSION=	2.7.1
DISTVERSIONPREFIX=v
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Versatile open-source tool for metagenomics

LICENSE=	GPLv3

LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo

USES=		autoreconf gmake
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	torognes

# sse2 required to compile on 32-bit archs
CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

.include <bsd.port.pre.mk>

#.if ${ARCH} == i386 || ${ARCH} == amd64
#CXXFLAGS+=	-msse2
#.endif

.include <bsd.port.post.mk>
