# New ports collection Makefile for:   Linux Matlab 7.7.0 R2008b
# Date created:        5 Jan 2010
# Whom:                Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	matlab-2010b-installer
PORTVERSION=	0.1
CATEGORIES=	math science
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/
# PKGNAMEPREFIX=	linux-

MAINTAINER=	jwbacon@tds.net
COMMENT=	Mathworks(r) Matlab installation tools

RUN_DEPENDS=	${LOCALBASE}/linux-sun-jdk1.6.0:${PORTSDIR}/java/linux-sun-jdk16

USE_LINUX=	yes

# OPTIONS=	MEX "Also requires linux_dist-gentoo-stage3" off

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

.if defined(WITH_MEX)
RUN_DEPENDS+=	${LOCALBASE}/gentoo-stage3:${PORTSDIR}/emulators/linux_dist-gentoo-stage3
.endif

SUB_FILES=	pkg-message

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/matlab-2010b-installer ${PREFIX}/bin

post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.post.mk>
