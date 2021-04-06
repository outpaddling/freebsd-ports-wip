# TODO
# Patch build system to install examples-python.  See plist vs pkg-plist.

PORTNAME=	ngs
PORTVERSION=	2016.12.23
CATEGORIES=	wip biology java

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	NCBI NGS language bindings

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_JAVA=	yes
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	06131412429136d32103203ff4397c8210e2bfd3

MAKEFILE=	Makefile.simple
CXXFLAGS+=	-fPIC
PLIST_SUB=	ARCH="${ARCH}"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so*

.include <bsd.port.mk>
