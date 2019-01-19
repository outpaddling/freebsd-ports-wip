# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD: head/comms/cutecom/Makefile 490472 2019-01-16 11:13:44Z tijl $

PORTNAME=		cutecom
DISTVERSIONPREFIX=	v
DISTVERSION=		0.50.0
CATEGORIES=		wip comms

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Graphical serial terminal for embedded programming

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	lsz:comms/lrzsz

USES=		cmake compiler:c++11-lang qt:5
# USE_QT=		qt3support qmake_build moc_build rcc_build uic_build
USE_QT=		buildtools_build core gui network qmake_build serialport widgets
USE_GITHUB=	yes

GH_ACCOUNT=	neundorf
GH_PROJECT=	CuteCom

PLIST_FILES=	bin/cutecom

.include <bsd.port.mk>
