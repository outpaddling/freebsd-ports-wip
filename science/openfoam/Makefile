# New ports collection makefile for:	openfoam
# Date created:		2013-01-08
# Whom:			Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	openfoam
PORTVERSION=	2.1.1
CATEGORIES=	science
# http://downloads.sourceforge.net/foam/OpenFOAM-2.1.1.tgz?use_mirror=mesh
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	../foam
DISTNAME=	OpenFOAM-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	bacon@sculpin.jbacon.dyndns.org
COMMENT=

FETCH_ARGS+=	-F

do-build:
	( cd ${WRKSRC} && ./Allwmake )

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
