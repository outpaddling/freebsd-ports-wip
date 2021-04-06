
PORTNAME=	format-cols
DISTVERSION=	g20200929
CATEGORIES=	wip textproc

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Format columns according to user parameters

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	1d533450

NO_BUILD=	yes
PLIST_FILES=	bin/format-cols libexec/format-cols.awk

pre-configure:
	${REINPLACE_CMD} -e \
		's|format-cols.awk|${PREFIX}/libexec/&|g' \
		${WRKSRC}/format-cols

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/format-cols ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/format-cols.awk ${STAGEDIR}${PREFIX}/libexec

.include <bsd.port.mk>
