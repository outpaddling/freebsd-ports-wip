# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD: head/x11-toolkits/qtermwidget/Makefile 420694 2016-08-23 15:11:50Z olivierd $

PORTNAME=	qtermwidget
PORTVERSION=	0.7.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://downloads.lxqt.org/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Terminal widget for QTerminal

LICENSE=	GPLv2

USES=		cmake:outsource compiler:c++11-lang pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_QT5=	buildtools_build core gui qmake_build widgets

CMAKE_ARGS+=	-DBUILD_DESIGNER_PLUGIN:BOOL=OFF -DUSE_QT5:BOOL=ON

CFLAGS+=	-DHAVE_UTEMPTER

.include <bsd.port.mk>
