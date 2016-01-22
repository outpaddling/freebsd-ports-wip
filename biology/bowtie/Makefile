# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	bowtie
PORTVERSION=	1.1.2
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Ultrafast, memory-efficient short read aligner

LICENSE=	ART10

RUN_DEPENDS=	webbrowser:${PORTSDIR}/www/webbrowser

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

# FIXME: bowtie-align dumps core when compiled with clang
# USE_GCC=	any
USES=		gmake perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	scripts/*.pl

USE_GITHUB=	yes
GH_ACCOUNT=	BenLangmead
GH_TAGNAME=	v${PORTVERSION}

WITH_DEBUG=	yes	# Disable stripping to debug core dumps

# Silence excessive gcc48 warnings
# CFLAGS+=	-Wno-unused-local-typedefs

.include <bsd.port.pre.mk>

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
