# $FreeBSD$

PORTNAME=	haplohseq
DISTVERSION=	0.1.2
CATEGORIES=	wip biology
MASTER_SITES=	https://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Identify regions of allelic imbalance

LICENSE=	MIT

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		compiler:c++11-lang gmake localbase:ldflags tar:xz

MAKEFILE=	makefile
LDFLAGS+=	-lpthread
MAKE_ENV=	STRIP=${STRIP}

PLIST_FILES=	bin/haplohseq

do-test:
	@(cd ${WRKSRC}/build/test && ${FILESDIR}/run-tests)

.include <bsd.port.mk>
