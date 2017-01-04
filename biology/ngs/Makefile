# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$
#
# TODO
# Patch build system to install examples-python.  See plist vs pkg-plist.

PORTNAME=	ngs
PORTVERSION=	2016.12.23
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	NCBI NGS language bindings

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

# USES=		gmake
USE_JAVA=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	d9e22b184e34794e1e1dddf56c59dc88c6d3ef5f

MAKEFILE=	Makefile.simple
CXXFLAGS+=	-fPIC

.include <bsd.port.mk>
