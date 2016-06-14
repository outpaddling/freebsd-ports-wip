# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	qtermwidget
PORTVERSION=	0.6.0
CATEGORIES=	sysutils

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Terminal widget for QTerminal

LICENSE=	GPLv2

USES=		cmake:outsource
USE_LDCONFIG=	yes
USE_QT5=	qmake_build

CMAKE_ARGS+=	-DBUILD_DESIGNER_PLUGIN=0 -DUSE_QT5=1

CFLAGS+=	-DHAVE_UTEMPTER

USE_GITHUB=	yes
GH_ACCOUNT=	lxde

.include <bsd.port.mk>
