# $FreeBSD$

# Note: pthreads performance on FreeBSD 10.1 is lacking compared to
# CentOS 6 on identical hardware.  Investigate tuning options.
# Must use the same version of dazz_db, daligner, pypeflow, and falcon!

PORTNAME=		DALIGNER
DISTVERSIONPREFIX=	V
DISTVERSION=		1.0-52
DISTVERSIONSUFFIX=	-g233274a
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Find all significant local alignments between reads

LICENSE=	BSD3CLAUSE

USES=		gmake tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
