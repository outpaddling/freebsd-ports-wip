# Created by: Jason Bacon
# $FreeBSD$

PORTNAME=		bowtie2
PORTVERSION=		2.2.7
DISTVERSIONPREFIX=	v
CATEGORIES=		biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Ultrafast, memory-efficient short read aligner

LICENSE=	ART10

RUN_DEPENDS=	webbrowser:${PORTSDIR}/www/webbrowser

USES=		gmake perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	scripts/*.pl

USE_GITHUB=	yes
GH_ACCOUNT=	BenLangmead

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

.include <bsd.port.mk>
