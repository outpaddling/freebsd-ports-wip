PORTNAME=	basic-stats
DISTVERSION=	0.1.0-8
DISTVERSIONSUFFIX=	-g0d0d609
CATEGORIES=	wip math

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Command-line tool to perform basic statistics on tabular data

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:wip/libxtend

USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

pre-build:
	cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/basic-stats

.include <bsd.port.mk>
