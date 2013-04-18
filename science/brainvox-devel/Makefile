# New ports collection makefile for:	brainvox
# Date created:		2007-08-02
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	brainvox
PORTVERSION=	3.12
CATEGORIES=	science
MASTER_SITES=	http://www.neuro.mcw.edu/~bacon/Ports/distfiles/
DISTNAME=	bv_tal_src
EXTRACT_SUFX=	.tgz
WRKSRC=		${WRKDIR}/brainvox/trunk

USE_GMAKE=	yes

MAINTAINER=	jwbacon@tds.net
COMMENT=	U Iowa 3D rendering

post-patch:
	#${CP} -f ${FILESDIR}/Makefile ${WRKSRC}
	${CP} -f ${FILESDIR}/config.FreeBSD ${WRKSRC}/config_files/FreeBSD
	${CP} -f ${FILESDIR}/myfont.c ${WRKSRC}/IrisGL

pre-build:
	(cd ${WRKSRC} && ${MAKE} FreeBSD)

.include <bsd.port.mk>
