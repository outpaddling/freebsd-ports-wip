# Created by: Jason Wayne Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	mothur
PORTVERSION=	1.36.1
DISTVERSIONPREFIX=v
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Bioinformatics tool for the microbial ecology community

LICENSE=	GPLv3

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs
RUN_DEPENDS=	uchime>=0:/usr/wip/biology/uchime

USES=		gmake ncurses readline

USE_GITHUB=	yes

MAKEFILE=	makefile
ALL_TARGET=	mothur
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/mothur

.include <bsd.port.mk>
