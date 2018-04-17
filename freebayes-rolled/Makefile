# $FreeBSD$

PORTNAME=	freebayes
PORTVERSION=	2018.03.23
CATEGORIES=	wip biology
MASTER_SITES=	https://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bayesian haplotype-based polymorphism discovery and genotyping

LICENSE=	MIT

USES=		gmake tar:xz

CFLAGS+=	-msse2
CXXFLAGS+=	--std=c++11
MAKE_JOBS_UNSAFE=	yes
PLIST_FILES=	bin/bamleftalign bin/freebayes

.include <bsd.port.pre.mk>

# GCC disables sse2 by default on i386, but it's required for vcflib
.if ${ARCH} == i386
CFLAGS+=	-msse2
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
