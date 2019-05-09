# $FreeBSD$

PORTNAME=	vsearch
DISTVERSIONPREFIX=v
DISTVERSION=	2.13.3
CATEGORIES=	wip biology

# Note: For PPC need power8 or later, little endian
MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Versatile open-source tool for metagenomics

LICENSE=	GPLv3

LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo

USES=		autoreconf gmake
USE_GITHUB=	yes

GH_ACCOUNT=	torognes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
# sse2 required to compile on non-ppc archs, off by default for i386
# configure script doesn't respect CXXFLAGS - report to upstream
CPPFLAGS+=	-msse2
.endif

PLIST_FILES=	bin/vsearch man/man1/vsearch.1.gz

.include <bsd.port.post.mk>
