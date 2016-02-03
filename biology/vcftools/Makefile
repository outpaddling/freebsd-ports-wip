# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	vcftools
PORTVERSION=	0.1.14
CATEGORIES=	biology
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Tools for working with VCF genomics files

LICENSE=	LGPL3

USES=		autoreconf gmake

BUILD_DEPENDS+=	pkg-config:${PORTSDIR}/devel/pkgconf

GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_TAGNAME=	v${PORTVERSION}

.include <bsd.port.mk>
