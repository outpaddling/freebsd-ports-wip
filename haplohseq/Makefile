# $FreeBSD$

PORTNAME=	haplohseq
PORTVERSION=	0.0.2019.08.29
CATEGORIES=	wip biology
MASTER_SITES=	https://mirror1.hpc.uwm.edu/Distfiles/
DISTNAME=	haplohseq_source

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Identify regions of allelic imbalance

LICENSE=	MIT

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		gmake localbase:ldflags zip

MAKEFILE=	makefile
LDFLAGS+=	-lpthread

PLIST_FILES=	bin/haplohseq

.include <bsd.port.mk>
