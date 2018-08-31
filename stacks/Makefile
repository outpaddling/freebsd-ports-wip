# $FreeBSD: head/biology/stacks/Makefile 475857 2018-07-29 22:18:44Z gerald $

PORTNAME=	stacks
DISTVERSION=	1.48
PORTREVISION=	1
CATEGORIES=	wip biology
MASTER_SITES=	http://catchenlab.life.illinois.edu/stacks/source/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Software pipeline for building loci from short-read sequences

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:openmp gmake python shebangfix
SHEBANG_FILES=	scripts/*.pl scripts/*.py
GNU_CONFIGURE=	yes

LDFLAGS+=	-lpthread

.include <bsd.port.mk>
