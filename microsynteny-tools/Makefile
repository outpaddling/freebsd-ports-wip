PORTNAME=	microsynteny-tools
DISTVERSION=	0.1.0-175
DISTVERSIONSUFFIX=	-gc471264
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for exploring microsyntenic differences among species
WWW=		https://github.com/auerlab/microsynteny-tools

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbiolibc.so:wip/biolibc libxtend.so:wip/libxtend
RUN_DEPENDS=	ncbi-blast+>0:biology/ncbi-blast+ \
		curl>0:ftp/curl \
		${PYTHON_PKGNAMEPREFIX}dna-features-viewer>0:biology/py-dna-features-viewer@${PY_FLAVOR} \
		auto-admin>=0.8.0:wip/auto-admin \
		biolibc-tools>0:wip/biolibc-tools

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

SHEBANG_FILES=	Scripts/*.py

.include <bsd.port.mk>
