# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	vsearch
PORTVERSION=	1.9.10
CATEGORIES=	biology

MAINTAINER=	jwbacon@tds.net
COMMENT=	Versatile open-source tool for metagenomics

LICENSE=	GPLv3

LIB_DEPENDS=	libsysinfo.so:${PORTSDIR}/devel/libsysinfo

# Uses inline assembly code
ONLY_FOR_ARCHS=	amd64

USES=		gmake
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	torognes
GH_TAGNAME=	v${PORTVERSION}

CXXFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/vsearch man/man1/vsearch.1.gz

.include <bsd.port.mk>
