PORTNAME=	gtime
DISTVERSION=	1.9
CATEGORIES=	wip misc
MASTER_SITES=	GNU/time
DISTNAME=	time-${PORTVERSION}

MAINTAINER=	ivalentine@arizona.edu
COMMENT=	GNU version of 'time' utility
WWW=		https://www.gnu.org/software/time/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	help2man:misc/help2man
TEST_DEPENDS=	check>=0.9.4:devel/check

USES=		gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
INSTALL_TARGET=	install-strip
TEST_ARGS=	CFLAGS+=-I${LOCALBASE}/include \
		LIBS+="-L${LOCALBASE}/lib -lcheck"
TEST_TARGET=	check

PLIST_FILES=	bin/${PKGBASE} \
		man/man1/${PKGBASE}.1.gz \
		share/info/time.info

post-patch:
.for f in help-version.sh time-exit-codes.sh time-max-rss.sh time-posix-quiet.sh
	@${REINPLACE_CMD} -e 's|env time|env ${WRKSRC}/time|g' ${WRKSRC}/tests/${f}
.endfor

post-build:
	${MKDIR} ${WRKDIR}/man1
	help2man -Nn "run programs and summarize system resource usage" ${WRKSRC}/time -o ${WRKDIR}/man1/${PKGBASE}.1

post-install:
	${INSTALL_MAN} ${WRKDIR}/man1/${PKGBASE}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
