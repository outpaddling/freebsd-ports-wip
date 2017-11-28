# Created by: Jason Bacon <jwb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vsearch
PORTVERSION=	1.10.2
DISTVERSIONPREFIX=      v
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Versatile open-source tool for metagenomics

LICENSE=	GPLv3

LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo

USES=		gmake
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	torognes

# sse2 required to compile on 32-bit archs
CXXFLAGS+=	-I${LOCALBASE}/include -msse2

PLIST_FILES=	bin/vsearch man/man1/vsearch.1.gz

.include <bsd.port.mk>
