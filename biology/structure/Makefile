# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

# http://pritchardlab.stanford.edu/structure_software/release_versions/v2.3.4/structure_kernel_source.tar.gz
PORTNAME=	structure
PORTVERSION=	2.3.4
CATEGORIES=	biology
MASTER_SITES=	http://pritchardlab.stanford.edu/structure_software/release_versions/v${PORTVERSION}/
DISTNAME=	${PORTNAME}_kernel_source

MAINTAINER=	jwbacon@tds.net
COMMENT=	Multi-locus genotype data to investigate population structure

# LICENSE=	unspecified

WRKSRC=		${WRKDIR}/structure_kernel_src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/structure ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
