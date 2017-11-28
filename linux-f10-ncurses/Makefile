# Created by:	Jason Bacon
# $FreeBSD$

PORTNAME=	ncurses
PORTVERSION=	5.6
CATEGORIES=	wip devel linux
MASTER_SITES=	http://archives.fedoraproject.org/pub/archive/fedora/linux/releases/10/Fedora/${LINUX_RPM_ARCH}/os/Packages/
PKGNAMEPREFIX=	linux-f10-
# DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

DISTFILES=	ncurses-base-${PORTVERSION}-20.20080927.fc10.${LINUX_RPM_ARCH}.rpm \
		ncurses-devel-${PORTVERSION}-20.20080927.fc10.${LINUX_RPM_ARCH}.rpm \
		ncurses-libs-${PORTVERSION}-20.20080927.fc10.${LINUX_RPM_ARCH}.rpm
MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Terminfo database required by Linux ncurses programs

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	20.20080927.fc10
USE_LDCONFIG=	yes

NO_STAGE=	yes

# DOCSDIR=	${PREFIX}/share/doc

.include <bsd.port.options.mk>

# FIXME
.if ! ${PORT_OPTIONS:MDOC}
post-install:
	${RM} -rf ${STAGEDIR}${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
	${RM} -rf ${STAGEDIR}${PREFIX}/usr/share/doc/${PORTNAME}-devel-${PORTVERSION}
.endif

.include <bsd.port.mk>
