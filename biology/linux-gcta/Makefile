# Created by: Jason Bacon <bacon@imacbsd.acadix.biz>
# $FreeBSD$

PORTNAME=	gcta
PORTVERSION=	1.26.0
CATEGORIES=	biology
MASTER_SITES=	http://cnsgenomics.com/software/gcta/
DISTNAME=	${PORTNAME}_${PORTVERSION}
PKGNAMEPREFIX=	linux-

MAINTAINER=	bacon@imacbsd.acadix.biz
COMMENT=	tool for Genome-wide Complex Trait Analysis

# Different from source (GPLv3)
LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT_License.txt

USES=		linux zip

NO_BUILD=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && ${UNZIP_CMD} ${DISTDIR}/${DISTFILES}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gcta64 ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/test.* ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
