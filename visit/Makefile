# New ports collection makefile for:	visit
# Date created:		2010-12-29
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	visit
PORTVERSION=	2.12.3
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	wip graphics science math
MASTER_SITES=	http://portal.nersc.gov/project/visit/releases/${PORTVERSION}/
#MASTER_SITE_SUBDIR=
#PKGNAMEPREFIX=
#PKGNAMESUFFIX=
DISTNAME=	${PORTNAME}${PORTVERSION}
#EXTRACT_SUFX=
#DISTFILES=
#DIST_SUBDIR=	${PORTNAME}
#EXTRACT_ONLY=

MAINTAINER=	bacon4000@gmail.com
COMMENT=	interactive parallel visualization and graphical analysis tool

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyVTK>0:math/py-pyvtk
# FIXME: Be less specific if possible to avoid breakage on vtk upgrade
LIB_DEPENDS+=	libvtkFiltersTexture-6.2.so:math/vtk6

WRKSRC=		${WRKDIR}/${DISTNAME}/src

#HAS_CONFIGURE=	yes
USES=		cmake python:3

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
