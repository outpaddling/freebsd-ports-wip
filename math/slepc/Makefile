# New ports collection makefile for:	slepc
# Date created:		2012-05-22
# Whom:			Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	slepc
PORTVERSION=	3.5.2
# DISTNAME=	${PORTNAME}-${PORTVERSION}-p5
CATEGORIES=	math
MASTER_SITES=	http://www.grycap.upv.es/slepc/download/distrib/

MAINTAINER=	jwbacon@tds.net
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

LIB_DEPENDS+=	libpetsc.so:/usr/wip/math/petsc

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
