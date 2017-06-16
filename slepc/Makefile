# New ports collection makefile for:	slepc
# Date created:		2012-05-22
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	slepc
PORTVERSION=	3.5.2
# DISTNAME=	${PORTNAME}-${PORTVERSION}-p5
CATEGORIES=	wip math
MASTER_SITES=	http://www.grycap.upv.es/slepc/download/distrib/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	large scale sparse eigenvalue problems on parallel computers

HAS_CONFIGURE=	yes
USES=		python fortran

CONFIGURE_ENV=	PETSC_ARCH= \
		PETSC_DIR=${LOCALBASE}/petsc

CONFIGURE_ARGS+=--prefix=${STAGEDIR}${PREFIX}/slepc

# USE_LDCONFIG=	${PREFIX}/${PORTNAME}/lib
USE_LDCONFIG=	yes

MAKEFILE=	makefile
MAKE_ENV+=	${CONFIGURE_ENV}
MAKE_JOBS_UNSAFE=	yes

LIB_DEPENDS+=	libpetsc.so:wip/petsc

post-build:
	cd ${WRKSRC} && make SLEPC_DIR=${WRKSRC} PETSC_DIR=${PREFIX}/petsc test

.include <bsd.port.mk>
