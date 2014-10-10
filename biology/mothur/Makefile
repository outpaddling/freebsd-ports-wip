# Created by: Jason Wayne Bacon <bacon@sciprog.ceas.uwm.edu>
# $FreeBSD$

PORTNAME=	Mothur
PORTVERSION=	1.33.3
CATEGORIES=	biology
MASTER_SITES=	http://www.mothur.org/w/images/6/65/
EXTRACT_SUFX=	.zip
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	bacon@sciprog.ceas.uwm.edu
COMMENT=

USES=		gmake fortran
# Causes clang to crash - submit a bug report
USE_GCC=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}.source
MAKEFILE=	makefile
ALL_TARGET=	mothur
MAKE_JOBS_UNSAFE=yes

post-patch:
	${REINPLACE_CMD} -e 's|gfortran|${FC}|g' ${WRKSRC}/makefile
	${REINPLACE_CMD} -e 's|-arch x86_64||g' ${WRKSRC}/makefile

.include <bsd.port.mk>
