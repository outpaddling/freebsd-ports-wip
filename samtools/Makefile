# Created by: Reed A. Cartwright <cartwright@asu.edu>
# $FreeBSD: head/biology/samtools/Makefile 476246 2018-08-02 19:28:36Z fernape $

PORTNAME=		samtools
DISTVERSION=		1.10
CATEGORIES=		wip biology

MAINTAINER=	cartwright@asu.edu
COMMENT=	Tools for manipulating next-generation sequencing data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	htslib>=1.10.2:biology/htslib
LIB_DEPENDS=	libhts.so:biology/htslib
TEST_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake localbase ncurses \
		perl5 python:env shebangfix

USE_GITHUB=	yes

USE_PERL5=	test
GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message
SHEBANG_FILES=	misc/*.pl misc/plot-bamstats test/test.pl

TEST_TARGET=	test

.include <bsd.port.mk>
