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

USES=		cpe makeinfo gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
CONFIGURE_ENV+=	MAKEINFO="${MAKEINFO} --no-split"
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
CPE_VENDOR=	gnu

PLIST_FILES=	bin/gtime \
		man/man1/gtime.1.gz \
		share/info/time.info

post-build:
	${MKDIR} ${WRKDIR}/man1
	help2man -Nn "run programs and summarize system resource usage" ${WRKSRC}/time -o ${WRKDIR}/man1/${PKGBASE}.1

post-install:
	${INSTALL_MAN} ${WRKDIR}/man1/${PKGBASE}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

pre-test:
.for f in help-version.sh time-exit-codes.sh time-max-rss.sh time-posix-quiet.sh
	@${REINPLACE_CMD} -e 's|env time|env ${WRKSRC}/time|g' ${WRKSRC}/tests/${f}
.endfor

.include <bsd.port.mk>
