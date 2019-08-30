# $FreeBSD$

PORTNAME=	haplohseq
PORTVERSION=	0.0.2019.08.29
CATEGORIES=	wip biology
# MASTER_SITES=	
DISTNAME=	haplohseq_source

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	identify regions of allelic imbalance

LICENSE=	MIT
# LICENSE_FILE=	

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		gmake zip
USE_GCC=	yes

LDFLAGS+=	-lpthread
MAKEFILE=	makefile
# MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
