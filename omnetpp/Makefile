PORTNAME=	omnetpp
DISTVERSION=	6.0.1
# DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSIONSUFFIX=	-linux-x86_64
CATEGORIES=	wip cad
MASTER_SITES=	https://github.com/omnetpp/omnetpp/releases/download/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Extensible, modular, component-based C++ simulation library
WWW=		https://omnetpp.org/

# Fake: Academic Public License
LICENSE=	GPLv2

BUILD_DEPENDS=	bison>0:devel/bison \
		${PYTHON_PKGNAMEPREFIX}posix_ipc>=0:devel/py-posix_ipc@${PY_FLAVOR}

USES=		gmake python tar:tgz

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFIGURE_ENV=	MAKE=gmake

# May need https://github.com/omnetpp/omnetpp/releases/download/omnetpp-6.0.1/omnetpp-6.0.1-linux-x86_64.tgz
# USE_GITHUB=	yes

do-configure:
	(cd ${WRKSRC} && . setenv && ./configure)

.include <bsd.port.mk>
