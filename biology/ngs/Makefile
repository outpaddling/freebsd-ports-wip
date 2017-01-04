# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$
#
# TODO
# Patch build system to install examples-python.  See plist vs pkg-plist.

PORTNAME=	ngs
PORTVERSION=	2016.12.23
CATEGORIES=	biology java

MAINTAINER=	bacon4000@gmail.com
COMMENT=	NCBI NGS language bindings

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_JAVA=	yes
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	4269d33da1db539145ccdfaed16a30a73b8463a4

MAKEFILE=	Makefile.simple
CXXFLAGS+=	-fPIC

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so*

.include <bsd.port.mk>
