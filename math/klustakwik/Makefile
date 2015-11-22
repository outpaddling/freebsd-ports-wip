# New ports collection makefile for:	klustakwik
# Date created:		23 Jan 2013
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	klustakwik
PORTVERSION=	2.0.1
CATEGORIES=	math science
MASTER_SITES=	SF/klustakwik/klustakwik
DISTNAME=	KlustaKwik-${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Unsupervised classification of multidimensional continuous data

LICENSE=	GPLv1

USE_BZIP2=	yes

MAKEFILE=	makefile
ALL_TARGET=	#empty

PLIST_FILES=	bin/KlustaKwik

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/KlustaKwik ${PREFIX}/bin

.include <bsd.port.mk>
