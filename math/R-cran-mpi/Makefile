# New ports collection makefile for:	Rmpi
# Date created:		22 March 2012
# Whom:			Jason Bacon <jwbacon@tds.net>

# $FreeBSD$
#

PORTNAME=	Rmpi
DISTVERSION=	0.5-9
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	MPI wrappers for R

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/Rmpi

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

# Doesn't work
#R_INS+=		--configure-args='--with-Rmpi-include=/usr/local/mpi/openmpi/include --with-Rmpi-libpath=/usr/local/mpi/openmpi/lib --with-Rmpi-type=OPENMPI'

#do-install:
#	R CMD INSTALL R CMD INSTALL --configure-args='--with-Rmpi-include=/usr/local/mpi/openmpi/include --with-Rmpi-libpath=/usr/local/mpi/openmpi/lib --with-Rmpi-type=OPENMPI' ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

.include <bsd.port.mk>
