PORTNAME=	miniconda-installer
DISTVERSION=	0.0.1-6
DISTVERSIONSUFFIX=	-gf6f0aa7
CATEGORIES=	wip sysutils
PKGNAMEPREFIX=	linux-

MAINTAINER=	bacon@moray.acadix.biz
COMMENT=	Aid for installing and using miniconda

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	auto-admin>0:sysutils/auto-admin

USES=		linux python:3.8
USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

NO_BUILD=	yes
PLIST_FILES=	bin/miniconda-installer bin/conda-shell

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/miniconda-installer ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/conda-shell ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
