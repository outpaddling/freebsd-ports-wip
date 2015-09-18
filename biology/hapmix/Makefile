# Created by: Jason Bacon <bacon@oyster.jbacon.dyndns.org>
# $FreeBSD$

PORTNAME=	hapmix
PORTVERSION=	1.2
CATEGORIES=	biology
MASTER_SITES=	http://cdn1.sph.harvard.edu/wp-content/uploads/sites/181/2012/10/
DISTNAME=	hapmix1.2.tar_.gz
MAINTAINER=	bacon@oyster.jbacon.dyndns.org
COMMENT=	Infer chromosomal segments of continental ancestry in admixed populations

USES=		zip

WRKSRC=		${WRKDIR}/HapmixRelease/src

MAKEFILE=	makefile
ALL_TARGET=	admix

# Bundles eigensrc and nicksrc

post-extract:
	cd ${WRKDIR} && tar zxf HAPMIX1.2.tar.gz

pre-build:
	cd ${WRKSRC} && ${MAKE} clean

.include <bsd.port.mk>
