# New ports collection makefile for:	domainmath
# Date created:		2013-06-05
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	domainmath
PORTVERSION=	0.1.3
CATEGORIES=	math
MASTER_SITES=	SF/domainmath/DomainMathIDE_v0.1.x/
DISTNAME=	DomainMathIDE_v${PORTVERSION}
EXTRACT_SUFX=	.7z

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Java 1.7 GUI for Octave

EXTRACT_DEPENDS+=	p7zip:${PORTSDIR}/archivers/p7zip

FETCH_ARGS+=	-F

do-extract:
	(cd ${WRKDIR} && p7zip -d ${PORTSDIR}/distfiles/${DISTNAME}${EXTRACT_SUFX})

.include <bsd.port.mk>
