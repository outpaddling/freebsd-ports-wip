# Created by:	Jason Bacon
# $FreeBSD$

PORTNAME=	bowtie
PORTVERSION=	1.0.0
CATEGORIES=	biology
MASTER_SITES=	https://github.com/BenLangmead/bowtie/archive/
DISTNAME=	v${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Ultrafast, memory-efficient short read aligner

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GMAKE=	yes

FETCH_ARGS+=	-F

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/bowtie \
		${WRKSRC}/bowtie-build \
		${WRKSRC}/bowtie-inspect \
		${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/*.pl \
		${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${CP} -R \
		${WRKSRC}/doc \
		${WRKSRC}/genomes \
		${WRKSRC}/indexes \
		${WRKSRC}/reads \
		${DATADIR}

.include <bsd.port.mk>
