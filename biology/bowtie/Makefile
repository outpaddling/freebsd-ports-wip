# Created by: Jason Bacon
# $FreeBSD$

PORTNAME=	bowtie
PORTVERSION=	1.0.1
CATEGORIES=	biology
MASTER_SITES=	http://github.com/BenLangmead/bowtie/archive/
DISTNAME=	v${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Ultrafast, memory-efficient short read aligner

LICENSE=	ART10

RUN_DEPENDS=	webbrowser:${PORTSDIR}/www/webbrowser

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

# Just for speed: Recent GCC has better optimizer
USE_GCC=	yes
USES=		gmake perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	scripts/*.pl

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
MAKE_ENV+=	POPCNT_CAPABILITY=0
.endif

post-patch:
	${REINPLACE_CMD} -e 's|lock_guard<MUTEX_T>|tthread::lock_guard<MUTEX_T>|g' ${WRKSRC}/log.h ${WRKSRC}/hit.h

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/bowtie \
		${WRKSRC}/bowtie-build \
		${WRKSRC}/bowtie-inspect \
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
