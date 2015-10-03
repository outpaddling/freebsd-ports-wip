# Created by: Jason Wayne Bacon <bacon@sciprog.ceas.uwm.edu>
# $FreeBSD$

PORTNAME=	mothur
PORTVERSION=	1.36.1
CATEGORIES=	biology

MAINTAINER=	bacon@sciprog.ceas.uwm.edu
COMMENT=

USES=		gmake fortran
# Causes clang to crash - submit a bug report
# USE_GCC=	yes

USE_GITHUB=	yes
GH_TAGNAME=	v${PORTVERSION}

# WRKSRC=		${WRKDIR}/${PORTNAME}/source
MAKEFILE=	makefile
ALL_TARGET=	mothur
MAKE_JOBS_UNSAFE=yes

post-patch:
	${REINPLACE_CMD} -e 's|-O3|-I${LOCALBASE}/include|g' ${WRKSRC}/makefile
	${REINPLACE_CMD} -e 's|gfortran|${FC}|g' ${WRKSRC}/source/makefile
	${REINPLACE_CMD} -e 's|-arch x86_64||g' ${WRKSRC}/makefile

.include <bsd.port.mk>
