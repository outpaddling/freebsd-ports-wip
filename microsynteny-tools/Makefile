PORTNAME=	microsynteny-tools
DISTVERSION=	0.1.0-133
DISTVERSIONSUFFIX=	-g2d9e28c
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for exploring microsyntenic differences among species

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbiolibc.so:wip/biolibc libxtend.so:wip/libxtend

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

SHEBANG_FILES=	Scripts/*.py

.include <bsd.port.mk>
