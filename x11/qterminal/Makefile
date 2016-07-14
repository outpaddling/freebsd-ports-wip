# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	qterminal
PORTVERSION=	0.6.0
CATEGORIES=	x11

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Lightweight Qt-based terminal emulator

LICENSE=	GPLv2

LIB_DEPENDS=	libqtermwidget5.so:/usr/wip/x11-toolkits/qtermwidget
RUN_DEPENDS=	liberation-fonts-ttf>=2.00:x11-fonts/liberation-fonts-ttf

USES=		cmake:outsource compiler:c++11-lang
USE_QT5+=	buildtools_build core gui linguisttools_build qmake_build widgets
USE_XORG+=	x11

CMAKE_ARGS+=	-DUSE_SYSTEM_QXT=0 -DUSE_QT5=1

USE_GITHUB=	yes
GH_ACCOUNT=	lxde

LDFLAGS+=	-L${LOCALBASE}/lib -lulog

.include <bsd.port.mk>
