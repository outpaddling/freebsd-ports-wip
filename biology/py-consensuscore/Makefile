# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	consensuscore
PORTVERSION=	2.3
CATEGORIES=	python
MASTER_SITES=	http://github.com/PacificBiosciences/ConsensusCore/archive/
DISTNAME=	smrtanalysis-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bacon4000@gmail.com
COMMENT=

USES=		python
USE_PYTHON=	autoplist distutils

BUILD_DEPENDS=	swig2.0:devel/swig20
CONFIGURE_ARGS+=	--swig=${LOCALBASE}/bin/swig2.0
MAKE_FLAGS+=	--swig=${LOCALBASE}/bin/swig2.0

WRKSRC=		${WRKDIR}/ConsensusCore-smrtanalysis-${PORTVERSION}

.include <bsd.port.mk>
