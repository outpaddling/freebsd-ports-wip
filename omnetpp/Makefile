PORTNAME=	omnetpp
DISTVERSION=	6.0.1
DISTVERSIONSUFFIX=	-linux-x86_64
CATEGORIES=	wip cad
MASTER_SITES=	https://github.com/omnetpp/omnetpp/releases/download/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Extensible, modular, component-based C++ simulation library
WWW=		https://omnetpp.org/

# Fake: Academic Public License
LICENSE=	GPLv2

BUILD_DEPENDS=	openscenegraph>=0:wip/openscenegraph \
		${PYTHON_PKGNAMEPREFIX}posix_ipc>=0:devel/py-posix_ipc@${PY_FLAVOR}

USES=		bison gmake python qmake localbase:ldflags qt:5 tar:tgz
USE_QT=		core buildtools:build qmake:build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes

# Simulate running ${WRKSRC}/setenv script before ./configure
CONFIGURE_ENV+=	MAKE=gmake PATH=${WRKSRC}/bin:${PATH} PYTHONPATH=${WRKSRC}/python:${PATH}
MAKE_ENV+=	MAKE=gmake PATH=${WRKSRC}/bin:${PATH} PYTHONPATH=${WRKSRC}/python:${PATH}

# Need https://github.com/omnetpp/omnetpp/releases/download/omnetpp-6.0.1/omnetpp-6.0.1-linux-x86_64.tgz, which contains additional files required for build.
# USE_GITHUB=	no

.include <bsd.port.mk>
