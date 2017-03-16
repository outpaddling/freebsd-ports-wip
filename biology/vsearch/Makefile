# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	vsearch
PORTVERSION=	2.4.2
DISTVERSIONPREFIX=v
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Versatile open-source tool for metagenomics

LICENSE=	GPLv3

LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo

USES=		autoreconf gmake
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	torognes

# sse2 required to compile on 32-bit archs
CXXFLAGS+=	-I${LOCALBASE}/include -msse2

OPTIONS_DEFINE=	USEARCH
OPTIONS_SUB=	yes
# If emulating usearch and usearch61 with vsearch works well, enable this
# OPTIONS_DEFAULT=USEARCH
USEARCH_DESC=	Install wrappers to use vsearch as usearch and usearch61
USEARCH_PLIST_FILES=	bin/usearch bin/usearch61

do-install-USEARCH-on:
	${INSTALL_SCRIPT} ${FILESDIR}/usearch* ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
