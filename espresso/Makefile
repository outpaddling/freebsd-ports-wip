
PORTNAME=	espresso
PORTVERSION=	5.0.2
CATEGORIES=	wip science
MASTER_SITES=	${MASTER_SITES_BASE}/116/403/
# espresso will try to download plugins during build phase if they are
# not already present in the archive directory.
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		XSpectra-5.0.2.tar.gz \
		qe-gipaw-5.0.3.tar.gz \
		SaX-2.0.2.tar.gz \
		${PLUGIN_DISTFILES}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Nanoscale electronic-structure calculations and materials modeling

LICENSE=	GPLv2

LIB_DEPENDS=	liblapack.so:math/lapack \
		libblas.so:math/blas \
		libfftw3.so:math/fftw3

GNU_CONFIGURE=	yes
USE_FORTRAN=	yes

# Slave packages for gui xspectra gipaw w90 want yambo?  
# Some could be independent packages?
# plumed must be compiled in - option?
# doc links
ALL_TARGET=	all links

# Causes gcc conftests to fail.  Do it post-configure instead.
# CPPFLAGS+=	-P -traditional

# Doesn't help
# LD=	${FC}

MAKE_JOBS_UNSAFE=	yes

MASTER_SITES_BASE=	http://www.qe-forge.org/gf/download/frsrelease

# install/plugins_list
PLUGIN_DISTFILES=want-2.4.0-base.tar.gz \
		yambo-3.2.5-rev.26.tar.gz \
		wannier90-1.2.tar.gz \
		plumed-1.3-qe.tar.gz \
		atomic-5.0.2.tar.gz \
		pwcond-5.0.2.tar.gz \
		neb-5.0.2.tar.gz \
		PHonon-5.0.2.tar.gz \
		tddfpt-5.0.2.tar.gz \
		PWgui-5.0.2.tgz

# FETCH creates files called index.php?file=filename
# I don't see a clean way to use -o in FETCH_ARGS with multiple DISTFILES
do-fetch:
	@${MKDIR} ${DISTDIR}/${DIST_SUBDIR}
	@(cd ${DISTDIR}/${DIST_SUBDIR} && ${FETCH_BINARY} -Fro \
		${DISTNAME}${EXTRACT_SUFX} \
		${MASTER_SITES}${DISTNAME}${EXTRACT_SUFX})
	@(cd ${DISTDIR}/${DIST_SUBDIR} && ${FETCH_BINARY} -Fro \
		XSpectra-5.0.2.tar.gz \
		${MASTER_SITES_BASE}/116/410/XSpectra-5.0.2.tar.gz)
	@(cd ${DISTDIR}/${DIST_SUBDIR} && ${FETCH_BINARY} -Fro \
		qe-gipaw-5.0.3.tar.gz \
		${MASTER_SITES_BASE}/146/473/qe-gipaw-5.0.3.tar.gz)
	@(cd ${DISTDIR}/${DIST_SUBDIR} && ${FETCH_BINARY} -Fro \
		SaX-2.0.2.tar.gz \
		${MASTER_SITES_BASE}/111/192/SaX-2.0.2.tar.gz)
.for file in ${PLUGIN_DISTFILES}
	@(cd ${DISTDIR}/${DIST_SUBDIR} && ${FETCH_BINARY} -Fro ${file} \
		http://files.qe-forge.org/index.php?file=${file})
.endfor

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/* ${WRKSRC}/archive

post-configure:
	${REINPLACE_CMD} \
		-e 's|CPPFLAGS[ \t]*=|CPPFLAGS = -P -traditional|g' \
		-e "s|/usr/local/bin/ld|${FC}|g" \
		${WRKSRC}/make.sys

post-build:
	@${MKDIR} ${WRKSRC}/scripts
	${MV} ${WRKSRC}/bin/iotk ${WRKSRC}/scripts

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/iotk ${STAGEDIR}${PREFIX}/bin
	for p in ${WRKSRC}/bin/*; do \
		${INSTALL_PROGRAM} $${p} \
		${STAGEDIR}${PREFIX}/bin; \
	done

.include <bsd.port.mk>
