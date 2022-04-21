PORTNAME=	microsynteny-tools
DISTVERSION=	0.1.0-149
DISTVERSIONSUFFIX=	-gb4484c6
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for exploring microsyntenic differences among species

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbiolibc.so:wip/biolibc libxtend.so:wip/libxtend
RUN_DEPENDS=	ncbi-blast+>0:biology/ncbi-blast+ \
		curl>0:ftp/curl \
		${PYTHON_PKGNAMEPREFIX}dna-features-viewer>0:biology/py-dna-features-viewer@${PY_FLAVOR}

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

SHEBANG_FILES=	Scripts/*.py

.include <bsd.port.mk>
