# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD: head/x11/qterminal/Makefile 420698 2016-08-23 15:18:26Z olivierd $
#
# FIXME: Depends on lxqt for translations
# FIXME: Default gemometry patches are not working

PORTNAME=	qterminal
PORTVERSION=	0.7.0
CATEGORIES=	x11

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Lightweight Qt-based terminal emulator

LICENSE=	GPLv2

LIB_DEPENDS=	libqtermwidget5.so.0.7.0:/usr/wip/x11-toolkits/qtermwidget
RUN_DEPENDS=	liberation-fonts-ttf>=2.00:x11-fonts/liberation-fonts-ttf

USES=		cmake:outsource compiler:c++11-lang gettext localbase \
		pkgconfig
USE_QT5+=	buildtools_build core gui linguisttools_build qmake_build widgets
USE_XORG+=	x11

CMAKE_ARGS+=	-DUSE_SYSTEM_QXT:BOOL=OFF -DUSE_QT5:BOOL=ON

USE_GITHUB=	yes
GH_ACCOUNT=	lxde

LDFLAGS+=	-lulog

.include <bsd.port.mk>
