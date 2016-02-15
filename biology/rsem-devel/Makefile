# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

# FIXME: Should install much more
# https://packages.debian.org/sid/amd64/rsem/filelist
PORTNAME=	rsem
PORTVERSION=	1.2.28
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	RNA-Seq by Expectation-Maximization

LICENSE=	GPLv3

# For samtools, which should be unbundled in the future, when RSEM
# depends only on htslib
USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	deweylab
GH_PROJECT=	RSEM
GH_TAGNAME=	v${PORTVERSION}

WRKSRC=		${WRKDIR}/RSEM-${PORTVERSION}

CXXFLAGS+=	-msse2

BUILD_DEPENDS+=	htslib>=1.3:${PORTSDIR}/biology/htslib

.include <bsd.port.mk>
