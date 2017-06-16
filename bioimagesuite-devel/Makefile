############################################################################
# New ports collection Makefile for:   bioimagesuite
# Date created:        2 jan 2007
# Whom:                Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#
#
############################################################################
# www.neuro.mcw.edu has the latest source distribution from which this port
# is built.  It will be updated as time permits and necessiaty requires.
#

PORTNAME=	bioimagesuite
PORTVERSION=	2.6
CATEGORIES=	wip science biology
MASTER_SITES=	http://www.bioimagesuite.org/download/src/
DISTNAME=	bioimagesuite-26_0_10_Nov_2008_source

MAINTAINER=	bacon4000@gmail.com
COMMENT=	BioImageSuite
WRKSRC=		${WRKDIR}/bioimagesuite26_src

USE_ZIP=	yes

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

#FETCH_ENV=      HTTP_AUTH="basic:anonymous:bioimagesuite"
BUILD_ENV=	BASE=${WRKSRC}/bioimagesuite

.include <bsd.port.pre.mk>

do-build:
	(cd ${WRKSRC}/build && ccmake ..)

do-install:
	${CP} -R ${WRKDIR}/* ${PREFIX}

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
