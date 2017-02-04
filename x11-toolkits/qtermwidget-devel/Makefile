# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD: head/x11-toolkits/qtermwidget/Makefile 429918 2016-12-29 14:29:18Z amdmi3 $

PORTNAME=	qtermwidget
PORTVERSION=	0.7.1
CATEGORIES=	x11-toolkits

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Terminal widget for QTerminal

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:outsource compiler:c++11-lang pkgconfig
USE_LDCONFIG=	yes
USE_QT5=	buildtools_build core gui qmake_build widgets

USE_GITHUB=	yes
GH_ACCOUNT=	lxde

OPTIONS_DEFINE=	UTF8
UTF8_LIB_DEPENDS=	libutf8proc.so:textproc/libutf8proc
UTF8_CMAKE_ON=	-DUSE_UTF8PROC:BOOL=ON

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-DHAVE_UTEMPTER
.endif

.include <bsd.port.post.mk>
