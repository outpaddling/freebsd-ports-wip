# Created by: Jason Bacon
# $FreeBSD: head/biology/bowtie2/Makefile 429003 2016-12-20 17:01:27Z jrm $

PORTNAME=	bowtie2
PORTVERSION=	2.3.2
DISTVERSIONPREFIX=	v
CATEGORIES=	wip biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Ultrafast, memory-efficient short read aligner

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libtbb.so:devel/tbb

# May also work on other 64-bit platforms, but untested
ONLY_FOR_ARCHS=	amd64
USES=		gmake perl5 python shebangfix
USE_PERL5=	run
SHEBANG_FILES=	bowtie2-build bowtie2-inspect scripts/*.pl

USE_GITHUB=	yes
GH_ACCOUNT=	BenLangmead

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/scripts
	${INSTALL_PROGRAM} \
		${WRKSRC}/bowtie2*-s \
		${WRKSRC}/bowtie2*-l \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/*.pl \
		${STAGEDIR}${DATADIR}/scripts

post-install-DOCS-on:
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	(cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
