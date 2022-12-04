PORTNAME=	omnetpp
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	6.0.1
CATEGORIES=	wip cad

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Extensible, modular, component-based C++ simulation library
WWW=		https://omnetpp.org/

# Fake: Academic Public License
LICENSE=	GPLv2

BUILD_DEPENDS=	openscenegraph>=0:wip/openscenegraph \
		${PYTHON_PKGNAMEPREFIX}posix_ipc>=0:devel/py-posix_ipc@${PY_FLAVOR}

USES=		bison gmake python qmake localbase:ldflags qt:5 tar:tgz
USE_QT=		core buildtools:build qmake:build

# Note: At this moment, there does not appear to be an easy way to
# build OmNet++ outside their blessed environments.  Making this
# port feasible may require some cooperation from upstream to better
# support portable builds from source.
USE_GITHUB=	yes

.include <bsd.port.mk>
