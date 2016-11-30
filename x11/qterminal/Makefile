# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD: head/x11/qterminal/Makefile 424271 2016-10-19 16:19:28Z marino $
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

USES=		cmake:outsource compiler:c++11-lang localbase:ldflags \
		pkgconfig
USE_QT5=	buildtools_build core gui qmake_build widgets x11extras
USE_XORG=	x11

CMAKE_ARGS+=	-DUSE_SYSTEM_QXT:BOOL=OFF

USE_GITHUB=	yes
GH_ACCOUNT=	lxde

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
LDFLAGS+=	-lulog
.endif

.include <bsd.port.post.mk>
