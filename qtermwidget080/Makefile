# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD: head/x11-toolkits/qtermwidget/Makefile 449591 2017-09-10 20:55:38Z gerald $

PORTNAME=	qtermwidget
PORTVERSION=	0.8.0
CATEGORIES=	wip x11-toolkits
MASTER_SITES=	LXQT

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Terminal widget for QTerminal

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	cmake:outsource compiler:c++11-lang gettext-runtime lxqt \
	pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_QT5=	buildtools_build core gui qmake_build linguisttools widgets
USE_LXQT=	buildtools

.include <bsd.port.mk>
