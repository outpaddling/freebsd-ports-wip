PORTNAME=	basic-stats
DISTVERSION=	0.1.0
CATEGORIES=	wip math

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Command-line tool to perform basic statistics on tabular data

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

PLIST_FILES=	bin/basic-stats

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/basic-stats

.include <bsd.port.mk>
