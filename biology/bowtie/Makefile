# Created by:	Jason Bacon
# $FreeBSD$

PORTNAME=	bowtie
PORTVERSION=	1.0.1
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
		${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -R \
		${WRKSRC}/doc \
		${WRKSRC}/genomes \
		${WRKSRC}/indexes \
		${WRKSRC}/reads \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
