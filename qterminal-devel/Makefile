# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD: head/x11/qterminal/Makefile 427977 2016-12-06 16:57:13Z olivierd $

PORTNAME=	qterminal
PORTVERSION=	0.7.1
CATEGORIES=	wip x11

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Lightweight Qt-based terminal emulator

LICENSE=	GPLv2

BUILD_DEPENDS=	qtermwidget==${PORTVERSION}:wip/qtermwidget-devel
RUN_DEPENDS=	liberation-fonts-ttf>=2.00:x11-fonts/liberation-fonts-ttf \
		qterminal-l10n>0:x11/qterminal-l10n \
		qtermwidget==${PORTVERSION}:wip/qtermwidget-devel

USES=		cmake:outsource compiler:c++11-lib localbase:ldflags \
		lxqt pkgconfig tar:xz
USE_QT5=	buildtools_build core gui linguisttools qmake_build \
		widgets x11extras
USE_XORG=	x11
USE_LXQT=	buildtools

CMAKE_ARGS+=	-DUSE_SYSTEM_QXT:BOOL=OFF

USE_GITHUB=	yes
GH_ACCOUNT=	lxde
# GH_TAGNAME=	d454a00c7ba20ac05714ddfd7fafc9704781a7f8

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
LDFLAGS+=	-lulog
.endif

.include <bsd.port.post.mk>
