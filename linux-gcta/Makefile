
PORTNAME=		gcta
DISTVERSION=		1.93.1
CATEGORIES=		wip biology
MASTER_SITES=		https://cnsgenomics.com/software/gcta/bin/
PKGNAMEPREFIX=		linux-
DISTNAME=		${PORTNAME}_${DISTVERSION}beta

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Genome-wide Complex Trait Analysis

# Different from source (GPLv3)
LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT_License.txt

ONLY_FOR_ARCHS=	amd64

USES=		linux zip

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gcta64 ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/test.* ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
