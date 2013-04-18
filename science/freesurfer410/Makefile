# New ports collection Makefile for:   Linux FreeSurfer 3.0
# Date created:        10 Mar 2006
# Whom:                Jason W. Bacon
#
# $FreeBSD$
#

PORTNAME=	freesurfer
PORTVERSION=	4.1.0
CATEGORIES=	science
MASTER_SITES=	http://localcache/~bacon/Ports/distfiles/ \
		ftp://surfer.nmr.mgh.harvard.edu/pub/dist/ \
		http://surfer.nmr.mgh.harvard.edu/pub/dist/ \
		http://www.neuro.mcw.edu/~bacon/Ports/distfiles/
DISTNAME=	${PORTNAME}-Linux-centos4-stable-pub-v${PORTVERSION}-full

MAINTAINER=	jwbacon@tds.net
COMMENT=	Cortical Surface Reconstruction

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg \
		${LINUXBASE}/usr/lib/libtiff.so.3:${PORTSDIR}/graphics/linux-tiff

USE_LINUX=	yes
USE_XLIB=	yes

SUB_FILES=	pkg-message freesurfer.cshrc freesurfer.profile license_freesurfer

NO_BUILD=	yes

WWW=		http://surfer.nmr.mgh.harvard.edu/

do-install:
	${MKDIR} ${PREFIX}/freesurfer ${PREFIX}/etc/mri
	${CP} -R ${WRKDIR}/freesurfer/* ${PREFIX}/freesurfer
	${INSTALL_SCRIPT} ${WRKDIR}/freesurfer.cshrc ${PREFIX}/etc/mri
	${INSTALL_SCRIPT} ${WRKDIR}/freesurfer.profile ${PREFIX}/etc/mri
	${INSTALL_SCRIPT} ${WRKDIR}/license_freesurfer ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/freesurfer_test ${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/env_warning ${PREFIX}/freesurfer

post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.mk>
