# Created by: Jason Bacon <bacon@oyster.jbacon.dyndns.org>
# $FreeBSD$

PORTNAME=	hapmix
PORTVERSION=	1.2
CATEGORIES=	biology
MASTER_SITES=	http://cdn1.sph.harvard.edu/wp-content/uploads/sites/181/2012/10/
DISTNAME=	hapmix1.2.tar_.gz
MAINTAINER=	bacon@oyster.jbacon.dyndns.org
COMMENT=	Infer chromosomal segments of continental ancestry in admixed populations

USES=		shebangfix zip
SHEBANG_FILES=	../bin/*.pl

WRKSRC=		${WRKDIR}/HapmixRelease/src

MAKEFILE=	makefile
ALL_TARGET=	admix

# Bundles eigensrc and nicksrc
RUN_DEPENDS=	eigensoft>=2015.09.17:/usr/wip/biology/eigensoft

post-extract:
	cd ${WRKDIR} && tar zxf HAPMIX1.2.tar.gz
	${REINPLACE_CMD} -e 's|/util/bin|/usr/bin|g' \
		${WRKSRC}/../bin/extract_output5.pl

pre-build:
	cd ${WRKSRC} && ${MAKE} clean

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/admix2 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/../bin/*.pl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
