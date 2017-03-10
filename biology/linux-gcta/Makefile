# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	gcta
PORTVERSION=	1.26.0
CATEGORIES=	biology
MASTER_SITES=	http://cnsgenomics.com/software/gcta/
DISTNAME=	${PORTNAME}_${PORTVERSION}
PKGNAMEPREFIX=	linux-

MAINTAINER=	bacon4000@gmail.com
COMMENT=	tool for Genome-wide Complex Trait Analysis

# Different from source (GPLv3)
LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT_License.txt

USES=		linux zip

NO_BUILD=	yes

# ${UNZIP_CMD} looking for /usr/local/bin/unzip for some reason
do-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && unzip ${DISTDIR}/${DISTFILES}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gcta64 ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/test.* ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
