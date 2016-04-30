# New ports collection Makefile for:   Linux FreeSurfer 3.0
# Date created:        10 Mar 2006
# Whom:                Jason W. Bacon
#
# $FreeBSD$
#

PORTNAME=	freesurfer
PORTVERSION=	3.0.5
CATEGORIES=	science
MASTER_SITES=	ftp://surfer.nmr.mgh.harvard.edu/pub/dist/ \
		http://surfer.nmr.mgh.harvard.edu/pub/dist/ \
		http://www.neuro.mcw.edu/~bacon/Ports/distfiles/
PKGNAMEPREFIX=	linux-
DISTNAME=	freesurfer-Linux-rh9-stable-pub-v3.0.5-full

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Cortical Surface Reconstruction

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libjpeg.so.62:graphics/linux-jpeg \
		${LINUXBASE}/usr/lib/libtiff.so.3:graphics/linux-tiff

USE_LINUX=	yes
USE_XLIB=	yes
PREFIX	?=	${LINUXBASE}${LOCALBASE}/freesurfer

SUB_FILES=	pkg-message

NO_BUILD=	yes

WWW=		http://surfer.nmr.mgh.harvard.edu/

do-install:
	${MKDIR} ${PREFIX}
	${CP} -R ${WRKDIR}/freesurfer/* ${PREFIX}

post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.mk>
