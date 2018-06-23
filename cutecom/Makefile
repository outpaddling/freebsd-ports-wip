# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD: head/comms/cutecom/Makefile 460452 2018-01-31 01:07:07Z jwb $

PORTNAME=	CuteCom
DISTVERSIONPREFIX=	v
DISTVERSION=	0.45.0
CATEGORIES=	wip comms

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Graphical serial terminal

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	lsz:comms/lrzsz

USES=		cmake
USE_QT5=	buildtools_build core gui qmake_build serialport widgets
USE_GITHUB=	yes
GH_ACCOUNT=	neundorf

PLIST_FILES=	bin/cutecom

.include <bsd.port.mk>
