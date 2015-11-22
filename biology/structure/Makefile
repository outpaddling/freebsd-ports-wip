# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

# http://pritchardlab.stanford.edu/structure_software/release_versions/v2.3.4/structure_kernel_source.tar.gz
PORTNAME=	structure
PORTVERSION=	2.3.4
CATEGORIES=	biology
MASTER_SITES=	http://pritchardlab.stanford.edu/structure_software/release_versions/v${PORTVERSION}/
DISTNAME=	${PORTNAME}_kernel_source

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Multi-locus genotype data to investigate population structure

# LICENSE=	unspecified

WRKSRC=		${WRKDIR}/structure_kernel_src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/structure ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
