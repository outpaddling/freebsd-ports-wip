PORTNAME=	MMseqs2
DISTVERSION=	13-45111
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Ultra fast and sensitive sequence search and clustering suite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_i386=	https://github.com/soedinglab/MMseqs2/issues/418

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cmake perl5 shebangfix
USE_PERL5=	build

SHEBANG_GLOB=	*.sh

USE_GITHUB=	yes
GH_ACCOUNT=	soedinglab

CMAKE_ARGS+=	-DUSE_SYSTEM_ZSTD:BOOL=ON
LDFLAGS+=	-lpthread

PLIST_FILES=	bin/mmseqs ${DATADIR}/bash-completion.sh

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-msse2	# Minimum for decent performance
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|MMSEQS_HOME/util|${DATADIR}|g' \
		${WRKSRC}/src/commons/Application.cpp

post-stage:
	${MV} ${STAGEDIR}${PREFIX}/util ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
