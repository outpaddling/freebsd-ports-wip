
PORTNAME=	consensuscore
PORTVERSION=	2.3
CATEGORIES=	wip python
MASTER_SITES=	http://github.com/PacificBiosciences/ConsensusCore/archive/
DISTNAME=	smrtanalysis-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=

USES=		python:3.6+
USE_PYTHON=	distutils

BUILD_DEPENDS=	swig2.0:devel/swig20
CONFIGURE_ARGS+=	--swig=${LOCALBASE}/bin/swig2.0
MAKE_FLAGS+=	--swig=${LOCALBASE}/bin/swig2.0

WRKSRC=		${WRKDIR}/ConsensusCore-smrtanalysis-${PORTVERSION}

.include <bsd.port.mk>
