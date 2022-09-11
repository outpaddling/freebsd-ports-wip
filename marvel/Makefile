PORTNAME=	MARVEL
PORTVERSION=	g20180308
CATEGORIES=	wip

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Assembler for noisy long read genomic data
WWW=		https://github.com/schloi/MARVEL

# Check this
LICENSE=	CC-BY-ND-4.0
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}networkx>=2.1:math/py-networkx@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}networkx>=2.1:math/py-networkx@${PY_FLAVOR}

USES=		autoreconf gmake python:3.6+
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	schloi
GH_TAGNAME=	1f693baf8420c2121cc40d18ed2088c6e81a713b

CFLAGS+=	-D_WITH_GETLINE
# MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
