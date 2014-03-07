# Created by: Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
# $FreeBSD$

PORTNAME=	siesta
PORTVERSION=	3.2
CATEGORIES=	science
MASTER_SITES=	http://departments.icmab.es/leem/siesta/CodeAccess/Code/
DISTNAME=	${PORTNAME}-${PORTVERSION}-pl-4
EXTRACT_SUFX=   .tgz

MAINTAINER=	bacon@sculpin.jbacon.dyndns.org
COMMENT=	Spanish Initiative for Electronic Simulations with Thousands of Atoms

USES=		gmake fortran

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+=--srcdir=../Src

FCFLAGS+=       -DGRID_DP -DPHI_GRID_SP -O2

WRKSRC=		${WRKDIR}/${DISTNAME}/Obj

MAKE_ENV+=      TARGET=""

PLIST_FILES=	bin/siesta bin/transiesta

pre-configure:
	(cd ${WRKSRC} && sh ../Src/obj_setup.sh && ${CP} ../Src/configure .)

# Does pkgsrc have a MAKE_TARGET equivalent?
do-build:
	(cd ${WRKSRC} && ${GMAKE} siesta)
	(cd ${WRKSRC} && ${MV} siesta siesta.save)
	(cd ${WRKSRC} && ${GMAKE} clean transiesta)

# Install with siesta group and 550?  Users must agree to license terms.
# Separate license for site installation requires restricting user access.
# chgrp below does not work
#	${CHMOD} 550 ${STAGEDIR}${PREFIX}/bin/siesta
#	${CHGRP} siesta ${STAGEDIR}${PREFIX}/bin/siesta
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/siesta.save ${STAGEDIR}${PREFIX}/bin/siesta
	${INSTALL_PROGRAM} ${WRKSRC}/transiesta ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
