# Created by: Jason Bacon
# $FreeBSD$

PORTNAME=	bowtie
PORTVERSION=	1.1.1
CATEGORIES=	biology
MASTER_SITES=	http://github.com/BenLangmead/bowtie/archive/
DISTNAME=	v${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Ultrafast, memory-efficient short read aligner

LICENSE=	ART10

RUN_DEPENDS=	webbrowser:${PORTSDIR}/www/webbrowser

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gmake perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	scripts/*.pl

.include <bsd.port.pre.mk>

# FIXME: bowtie-align dumps core when compiled with clang
# Just for speed: Recent GCC has better optimizer
# .if ${OSVERSION} < 1000000
USE_GCC=	yes
# .endif

.if ${ARCH} == i386
MAKE_ENV+=	POPCNT_CAPABILITY=0
.endif

do-install:
	${INSTALL_SCRIPT} \
		${WRKSRC}/bowtie \
		${WRKSRC}/bowtie-build \
		${WRKSRC}/bowtie-inspect \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} \
		${WRKSRC}/bowtie*-s \
		${WRKSRC}/bowtie*-l \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/*.pl \
		${FILESDIR}/bowtie-manual \
		${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \
		'genomes indexes reads' \
		${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \
		\* \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
