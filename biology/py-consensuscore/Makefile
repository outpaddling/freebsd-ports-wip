# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	consensuscore
PORTVERSION=	2.3
CATEGORIES=	python
MASTER_SITES=	http://github.com/PacificBiosciences/ConsensusCore/archive/
DISTNAME=	smrtanalysis-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwbacon@tds.net
COMMENT=

USES=		python
USE_PYTHON=	autoplist distutils

BUILD_DEPENDS=	swig2.0:${PORTSDIR}/devel/swig20
CONFIGURE_ARGS+=	--swig=${LOCALBASE}/bin/swig2.0
MAKE_FLAGS+=	--swig=${LOCALBASE}/bin/swig2.0

WRKSRC=		${WRKDIR}/ConsensusCore-smrtanalysis-${PORTVERSION}

.include <bsd.port.mk>
