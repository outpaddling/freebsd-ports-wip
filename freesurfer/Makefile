# New ports collection makefile for:	freesurfer
# Date created:		2012-05-06
# Whom:			Jason Bacon <jwb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freesurfer
PORTVERSION=	5.1.0
CATEGORIES=	wip science
MASTER_SITES=

MAINTAINER=	jwb@FreeBSD.org
COMMENT=

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_AUTOTOOLS=	autoconf automake libtool

# http://surfer.nmr.mgh.harvard.edu/fswiki/DevelopersGuide
# Freesurfer builds against the following set of open-sourced libraries, thus, these must be installed prior to building:
# 
#    MNI 1.4
#    VXL 1.13.0 
#
# These must be installed if you want to build the GUI apps:
#
#     Tcl 8.4.6
#     Tk 8.4.6
#     Tix 8.1.4
#     BLT 2.4z
#     VTK 5.6
#     KWWidgets - CVS checkout
#     Qt 3 

USE_TCL=	84+
USE_TK=		84+
USE_QT_VER=	3	# Can this be 4?

LIB_DEPENDS=	vtkCommon.5:math/vtk5 \
		minc:science/minc \
		Tix8:x11-toolkits/tix \
		BLT24:x11-toolkits/blt \
		KWWidgets:../../science/kwwidgets
BUILD_DEPENDS=	${LOCALBASE}/lib/libvul.a:../../science/vxl

#do-fetch:
#	${MKDIR} ${WRKDIR}
#	(cd ${WRKDIR} && \
#	cvs -d :pserver:anonymous@fsvm.nmr.mgh.harvard.edu:/usr/fscvsroot login && \
#	cvs -d :pserver:anonymous@fsvm.nmr.mgh.harvard.edu:/usr/fscvsroot checkout -P -r stable5 dev)

#do-configure:
#	(cd ${WRKSRC} && ./setup_configure && ./configure --prefix=${PREFIX})

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
