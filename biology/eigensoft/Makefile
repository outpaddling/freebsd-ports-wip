# Created by: Jason Bacon <bacon@oyster.jbacon.dyndns.org>
# $FreeBSD$

PORTNAME=	eigensoft
PORTVERSION=	2015.09.17
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon@oyster.jbacon.dyndns.org
COMMENT=	Population genetics and stratification correction method

LIB_DEPENDS=	libgsl.so:${PORTSDIR}/math/gsl \
		libopenblas.so:${PORTSDIR}/math/openblas \
		liblapack.so:${PORTSDIR}/math/lapack
BUILD_DEPENDS=	${LOCALBASE}/include/lapacke_mangling.h:${PORTSDIR}/math/lapacke

USES=		fortran gmake shebangfix tar:xz
SHEBANG_FILES=	${WRKSRC}/../bin/evec2pca-ped.perl \
		${WRKSRC}/../bin/evec2pca.perl \
		${WRKSRC}/../bin/fixgreen \
		${WRKSRC}/../bin/gc.perl \
		${WRKSRC}/../bin/ploteig \
		${WRKSRC}/../bin/smarteigenstrat.perl \
		${WRKSRC}/../bin/smartpca.perl

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

MAKE_ENV=	LOCALBASE=${LOCALBASE} FC=${FC}

# Just for debugging
MAKE_JOBS_UNSAFE=	yes

pre-build:
	cd ${WRKSRC} && ${GMAKE} clobber

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/../bin/baseprog \
		${WRKSRC}/../bin/convertf \
		${WRKSRC}/../bin/eigenstrat \
		${WRKSRC}/../bin/eigenstratQTL \
		${WRKSRC}/../bin/mergeit \
		${WRKSRC}/../bin/pca \
		${WRKSRC}/../bin/pcatoy \
		${WRKSRC}/../bin/smarteigenstrat \
		${WRKSRC}/../bin/smartpca \
		${WRKSRC}/../bin/smartrel \
		${WRKSRC}/../bin/twstats \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/../bin/evec2pca-ped.perl \
		${WRKSRC}/../bin/evec2pca.perl \
		${WRKSRC}/../bin/fixgreen \
		${WRKSRC}/../bin/gc.perl \
		${WRKSRC}/../bin/ploteig \
		${WRKSRC}/../bin/smarteigenstrat.perl \
		${WRKSRC}/../bin/smartpca.perl \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
