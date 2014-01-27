# New ports collection makefile for:	quantum-espresso
# Date created:		2013-10-06
# Whom:			Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	espresso
PORTVERSION=	5.0.2
CATEGORIES=	science
MASTER_SITES=	http://qe-forge.org/gf/download/frsrelease/116/403/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		XSpectra-5.0.2.tar.gz \
		qe-gipaw-5.0.3.tar.gz \
		SaX-2.0.2.tar.gz \
		${PLUGINS_DISTFILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	bacon@sculpin.jbacon.dyndns.org
COMMENT=

GNU_CONFIGURE=	yes
USE_FORTRAN=	yes

LIB_DEPENDS=	lapack:${PORTSDIR}/math/lapack \
		blas:${PORTSDIR}/math/blas

# Causes gcc conftests to fail
# CPPFLAGS+=	-P -traditional

# Doesn't help
# LD=	${FC}

MAKE_JOBS_UNSAFE=	yes

# install/plugins_list
PLUGINS_DISTFILES=want-2.4.0-base.tar.gz \
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
	@${FETCH_BINARY} -Fro \
		${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${MASTER_SITES}${DISTNAME}${EXTRACT_SUFX}
	@${FETCH_BINARY} -Fro \
		${DISTDIR}/${DIST_SUBDIR}/XSpectra-5.0.2.tar.gz \
		http://www.qe-forge.org/gf/download/frsrelease/116/410/XSpectra-5.0.2.tar.gz
	@${FETCH_BINARY} -Fro \
		${DISTDIR}/${DIST_SUBDIR}/qe-gipaw-5.0.3.tar.gz \
		http://www.qe-forge.org/gf/download/frsrelease/146/473/qe-gipaw-5.0.3.tar.gz
	@${FETCH_BINARY} -Fro \
		${DISTDIR}/${DIST_SUBDIR}/SaX-2.0.2.tar.gz \
		http://www.qe-forge.org/gf/download/frsrelease/111/192/SaX-2.0.2.tar.gz

.for file in ${PLUGINS_DISTFILES}
	@${FETCH_BINARY} -Fro ${DISTDIR}/${DIST_SUBDIR}/${file} \
		http://files.qe-forge.org/index.php?file=${file}
.endfor

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/* ${WRKSRC}/archive

post-configure:
	${REINPLACE_CMD} \
		-e 's|CPPFLAGS[ \t]*=|CPPFLAGS = -P -traditional|g' \
		-e "s|/usr/local/bin/ld|${FC}|g" \
		${WRKSRC}/make.sys

post-build:
	${MKDIR} ${WRKSRC}/scripts
	${MV} ${WRKSRC}/bin/iotk ${WRKSRC}/scripts

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/iotk ${STAGEDIR}${PREFIX}/bin
	for p in ${WRKSRC}/bin/*; do \
		${INSTALL_PROGRAM} $${p} \
		${STAGEDIR}${PREFIX}/bin; \
	done

.include <bsd.port.mk>
