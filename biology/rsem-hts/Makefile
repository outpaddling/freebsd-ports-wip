# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

# FIXME: Should install much more
# https://packages.debian.org/sid/amd64/rsem/filelist
PORTNAME=	rsem
PORTVERSION=	9605ef82ebd4e1b20bf447de2c6ed752e902aa7b
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	RNA-Seq by Expectation-Maximization

LICENSE=	GPLv3

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	deweylab
GH_PROJECT=	RSEM
# GH_TAGNAME=	v${PORTVERSION}

WRKSRC=		${WRKDIR}/RSEM-${PORTVERSION}

BUILD_DEPENDS+=	htslib>=1.3:${PORTSDIR}/biology/htslib

.include <bsd.port.mk>
