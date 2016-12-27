# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD: head/x11-toolkits/qtermwidget/Makefile 424270 2016-10-19 16:17:40Z marino $

PORTNAME=	qtermwidget
PORTVERSION=	0.6.0
CATEGORIES=	x11-toolkits

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Terminal widget for QTerminal

LICENSE=	GPLv2

USES=		cmake:outsource compiler:c++11-lang pkgconfig
USE_LDCONFIG=	yes
USE_QT5=	buildtools_build core gui qmake_build widgets

CMAKE_ARGS+=	-DBUILD_DESIGNER_PLUGIN:BOOL=OFF -DUSE_QT5:BOOL=ON

USE_GITHUB=	yes
GH_ACCOUNT=	lxde

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-DHAVE_UTEMPTER
.endif

.include <bsd.port.post.mk>
