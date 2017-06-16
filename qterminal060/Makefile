# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD: head/x11/qterminal/Makefile 424271 2016-10-19 16:19:28Z marino $

PORTNAME=	qterminal
PORTVERSION=	0.6.0
CATEGORIES=	wip x11

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Lightweight Qt-based terminal emulator

LICENSE=	GPLv2

LIB_DEPENDS=	libqtermwidget5.so:wip/qtermwidget060
RUN_DEPENDS=	liberation-fonts-ttf>=2.00:x11-fonts/liberation-fonts-ttf

USES=		cmake:outsource compiler:c++11-lang gettext localbase:ldflags \
		pkgconfig
USE_QT5+=	buildtools_build core gui linguisttools_build qmake_build widgets
USE_XORG+=	x11

CMAKE_ARGS+=	-DUSE_SYSTEM_QXT:BOOL=OFF -DUSE_QT5:BOOL=ON

USE_GITHUB=	yes
GH_ACCOUNT=	lxde

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
LDFLAGS+=	-lulog
.endif

.include <bsd.port.post.mk>
