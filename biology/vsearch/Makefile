# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	vsearch
PORTVERSION=	1.9.10
CATEGORIES=	biology

MAINTAINER=	jwbacon@tds.net
COMMENT=	Versatile open-source tool for metagenomics

LICENSE=	GPLv3

LIB_DEPENDS=	libsysinfo.so:${PORTSDIR}/devel/libsysinfo

USES=		gmake
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	torognes
GH_TAGNAME=	v${PORTVERSION}

# sse2 required to compile on 32-bit archs
CXXFLAGS+=	-I${LOCALBASE}/include -msse2

PLIST_FILES=	bin/vsearch man/man1/vsearch.1.gz

.include <bsd.port.mk>
