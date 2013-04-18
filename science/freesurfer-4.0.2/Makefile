# New ports collection Makefile for:   Linux FreeSurfer 3.0
# Date created:        10 Mar 2006
# Whom:                Jason W. Bacon
#
# $FreeBSD$
#

PORTNAME=	freesurfer
PORTVERSION=	4.0.2
CATEGORIES=	science
MASTER_SITES=	ftp://surfer.nmr.mgh.harvard.edu/pub/dist/ \
		http://surfer.nmr.mgh.harvard.edu/pub/dist/ \
		http://www.neuro.mcw.edu/~bacon/Ports/distfiles/
DISTNAME=	freesurfer-Linux-rh9-stable-pub-v4.0.2-full

MAINTAINER=	jwbacon@tds.net
COMMENT=	Cortical Surface Reconstruction

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg \
		${LINUXBASE}/usr/lib/libtiff.so.3:${PORTSDIR}/graphics/linux-tiff

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
