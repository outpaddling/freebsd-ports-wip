# $FreeBSD$

PORTNAME=	freebayes
PORTVERSION=	2018.03.23
CATEGORIES=	wip biology
MASTER_SITES=	https://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bayesian haplotype-based polymorphism discovery and genotyping

LICENSE=	MIT

USES=		gmake tar:xz
# SeqLib does not build with clang
USE_GCC=	yes

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/bamleftalign bin/freebayes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
