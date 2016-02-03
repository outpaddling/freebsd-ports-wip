# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	eigensoft
PORTVERSION=	2015.09.17
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
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

# What are these binaries?
#		${WRKSRC}/../bin/smarteigenstrat \
#		${WRKSRC}/../bin/smartpca \
#		${WRKSRC}/../bin/smartrel \

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/../src/baseprog \
		${WRKSRC}/../src/convertf \
		${WRKSRC}/../src/eigensrc/eigenstrat \
		${WRKSRC}/../src/eigensrc/eigenstratQTL \
		${WRKSRC}/../src/mergeit \
		${WRKSRC}/../src/pca \
		${WRKSRC}/../src/eigensrc/pcatoy \
		${WRKSRC}/../src/eigensrc/twstats \
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
