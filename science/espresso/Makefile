# New ports collection makefile for:	quantum-espresso
# Date created:		2013-10-06
# Whom:			Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	espresso
PORTVERSION=	5.0.2
CATEGORIES=	science
MASTER_SITES=	http://qe-forge.org/gf/download/frsrelease/116/403/ \
		http://files.qe-forge.org/index.php?file=
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz \
		want-2.4.0-base.tar.gz \
		yambo-3.2.5-rev.26.tar.gz \
		wannier90-1.2.tar.gz \
		sax-2.0.3.tar.gz \
		qe-gipaw-5.0.tar.gz \
		plumed-1.3-qe.tar.gz \
		atomic-5.0.2.tar.gz \
		xspectra-5.0.2.tar.gz \
		pwcond-5.0.2.tar.gz \
		neb-5.0.2.tar.gz \
		PHonon-5.0.2.tar.gz \
		tddfpt-5.0.2.tar.gz \
		PWgui-5.0.2.tgz
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	bacon@sculpin.jbacon.dyndns.org
COMMENT=

GNU_CONFIGURE=	yes
USE_FORTRAN=	yes

LIB_DEPENDS=	lapack:${PORTSDIR}/math/lapack

# Causes gcc conftests to fail
# CPPFLAGS+=	-P -traditional

# Doesn't help
# LD=	${FC}

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
	${MKDIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/iotk ${DESTDIR}${PREFIX}/bin
	for p in ${WRKSRC}/bin/*; do \
		${INSTALL_PROGRAM} $${p} \
		${DESTDIR}${PREFIX}/bin; \
	done

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
