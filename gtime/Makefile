PORTNAME=	time
DISTVERSION=	1.9
CATEGORIES=	wip misc
MASTER_SITES=	GNU/time
PKGNAMEPREFIX=	g

MAINTAINER=	ivalentine@arizona.edu
COMMENT=	GNU version of 'time' utility
WWW=		https://www.gnu.org/software/time/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	help2man:misc/help2man

USES=		cpe gmake makeinfo
CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
CONFIGURE_ENV+=	MAKEINFO="${MAKEINFO} --no-split"
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

DATADIR=	${PREFIX}/share/${PKGBASE}
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
INFO=		time
PLIST_FILES=	bin/gtime \
		man/man1/gtime.1.gz
PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

post-build:
	${MKDIR} ${WRKDIR}/man1
	help2man -Nn "run programs and summarize system resource usage" ${WRKSRC}/time -o ${WRKDIR}/man1/${PKGBASE}.1

post-install:
	${INSTALL_MAN} ${WRKDIR}/man1/${PKGBASE}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

pre-test:
.for f in help-version.sh time-exit-codes.sh time-max-rss.sh time-posix-quiet.sh
	@${REINPLACE_CMD} -e 's|env time|env ${WRKSRC}/time|g' ${WRKSRC}/tests/${f}
.endfor

.include <bsd.port.mk>
