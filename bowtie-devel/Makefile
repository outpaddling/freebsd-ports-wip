
# Test new versions with Trinity before upgrading

PORTNAME=		bowtie
PORTVERSION=		1.2.3
DISTVERSIONPREFIX=	v
CATEGORIES=	wip 	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Ultrafast, memory-efficient short read aligner

LICENSE=	ART10

# May also work on other 64-bit platforms, but untested
ONLY_FOR_ARCHS=	amd64

LIB_DEPENDS+=	libtbb.so:devel/tbb

# FIXME: bowtie-align 1.2.1 intermittently dumps core when compiled with clang
USES=		gmake perl5 python:run shebangfix
# USE_GCC=	yes
USE_PERL5=	run
USE_GITHUB=	yes

SHEBANG_FILES=	bowtie bowtie-build bowtie-inspect scripts/*.pl scripts/*.sh
GH_ACCOUNT=	BenLangmead

MAKE_ENV+=	RELEASE_BIN=1
# MAKE_JOBS_UNSAFE=	yes
SUB_FILES=	bowtie-test

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/scripts
	${INSTALL_SCRIPT} \
		${WRKSRC}/bowtie \
		${WRKSRC}/bowtie-build \
		${WRKSRC}/bowtie-inspect \
		${WRKDIR}/bowtie-test \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/*.pl \
		${STAGEDIR}${DATADIR}/scripts
	cd ${WRKSRC} && ${COPYTREE_SHARE} \
		'genomes indexes reads' \
		${STAGEDIR}${DATADIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*-[sl]

.include <bsd.port.mk>
