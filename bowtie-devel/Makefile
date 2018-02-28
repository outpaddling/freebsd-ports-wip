# $FreeBSD$
# Test new versions with Trinity before upgrading

PORTNAME=		bowtie
PORTVERSION=		1.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	wip 	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Ultrafast, memory-efficient short read aligner

LICENSE=	ART10

LIB_DEPENDS+=	libtbb.so:devel/tbb

# May also work on other 64-bit platforms, but untested
ONLY_FOR_ARCHS=	amd64

LIB_DEPENDS+=	libtbb.so:devel/tbb

# FIXME: bowtie-align intermittently dumps core when compiled with clang
# GCC 4.2 does not provide good performance
# USE_GCC=	yes
USES=		gmake perl5 python:run shebangfix
USE_PERL5=	run
SHEBANG_FILES=	bowtie bowtie-build bowtie-inspect scripts/*.pl

USE_GITHUB=	yes
GH_ACCOUNT=	BenLangmead

MAKE_ENV+=	RELEASE_BIN=1

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/scripts
	${INSTALL_SCRIPT} \
		${WRKSRC}/bowtie \
		${WRKSRC}/bowtie-build \
		${WRKSRC}/bowtie-inspect \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/*.pl \
		${STAGEDIR}${DATADIR}/scripts
	cd ${WRKSRC} && ${COPYTREE_SHARE} \
		'genomes indexes reads' \
		${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \
		\* \
		${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*-[sl]

.include <bsd.port.mk>
