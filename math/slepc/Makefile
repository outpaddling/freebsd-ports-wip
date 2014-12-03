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
USE_PYTHON=	yes
USE_FORTRAN=	yes

CONFIGURE_ENV=	PETSC_ARCH=${OPSYS:L} \
		PETSC_DIR=${LOCALBASE}/petsc

# USE_LDCONFIG=	${PREFIX}/${PORTNAME}/lib

# MAKE_ENV+=	PETSC_DIR=${LOCALBASE}/petsc

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
