# New ports collection makefile for:	bowtie
# Date created:		2013-08-23
# Whom:			Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
#
# $FreeBSD$
#

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

.include <bsd.port.mk>
