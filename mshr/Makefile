# $FreeBSD$

PORTNAME=	mshr
DISTVERSION=	2017.2.0
CATEGORIES=	wip
MASTER_SITES=	https://bitbucket.org/fenics-project/mshr/downloads/

MAINTAINER=	bacon@manatee.acadix.biz
COMMENT=	Mesh generation component of FEniCS

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

# Yes, the ABI number is necessary
LIB_DEPENDS=	libdolfin.so.${DISTVERSION}:wip/dolfin

USES=		cmake:outsource

.include <bsd.port.mk>
