# New ports collection makefile for:	nifticlib
# Date created:		2007-04-27
# Whom:			Jason W. Bacon
#
# $FreeBSD$
#

PORTNAME=	nifticlib
PORTVERSION=	2.0.0
CATEGORIES=	science graphics
MASTER_SITES=	${SF}
MASTER_SITE_SUBDIR=	niftilib

MAINTAINER=	jwbacon@tds.net
COMMENT=	Neuroimaging Infoirmatics Technology Initiative data format

USE_GMAKE=	yes

# AFNI currently has nifti embedded in the distfile and installs the
# nifti bins by itself.
CONFLICTS=	afni-[0-9]* dbh-[0-9]*

MAN1=		nifticlib.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/*.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include
	${INSTALL_MAN} ${FILESDIR}/nifticlib.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
