# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	ea-utils
PORTVERSION=	1.1.2
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
DISTNAME=	${PORTNAME}.${PORTVERSION}-806

MAINTAINER=	jwbacon@tds.net
COMMENT=	Command-line tools for processing fastq sequence data

# Dist makefile uses GNU make extensions
USES=		gmake

# varcall.cpp
LIB_DEPENDS=	libgsl.so:${PORTSDIR}/math/gsl

# Unbundled dependencies
BUILD_DEPENDS=	samtools>=0.1.19:/usr/wip/biology/samtools \
		google-sparsehash>=2.0.2:${PORTSDIR}/devel/google-sparsehash
RUN_DEPENDS=	${BUILD_DEPENDS}

CFLAGS+=	-I${LOCALBASE}/include -D_WITH_GETLINE
MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
