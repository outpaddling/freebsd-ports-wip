# Created by: Jason Bacon <bacon@unixdev.ceas.uwm.edu>
# $FreeBSD$

PORTNAME=	apt
PORTVERSION=	1.19.0
CATEGORIES=	biology
MASTER_SITES=	http://media.affymetrix.com/Download/updates/
PKGNAMEPREFIX=	linux-
DISTNAME=	APT_${PORTVERSION}_Linux_64_bit_x86_binaries

MAINTAINER=	bacon@unixdev.ceas.uwm.edu
COMMENT=	Command line programs for working with Affymetrix GeneChip® arrays

# Not sure of version
LICENSE=	GPLv2
#LICENSE_FILE=

USES=		zip

WRKSRC=		${WRKDIR}/apt-${PORTVERSION}-x86_64-intel-linux

do-build:
	${MV} ${WRKSRC}/bin/apt-annotation-converter.config ${WRKSRC}
	${MV} ${WRKSRC}/bin/axiom_param_conversion.txt ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} \
		${WRKSRC}/*.txt \
		${WRKSRC}/*.config \
		${WRKSRC}/*.rtf \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
