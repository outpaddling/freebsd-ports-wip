PORTNAME=	MMseqs2
DISTVERSION=	13-45111
PORTREVISION=	2
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Ultra fast and sensitive sequence search and clustering suite
WWW=		https://github.com/soedinglab/MMseqs2

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_i386=	https://github.com/soedinglab/MMseqs2/issues/418

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cmake perl5 shebangfix
USE_GITHUB=	yes
USE_PERL5=	build

SHEBANG_GLOB=	*.sh
GH_ACCOUNT=	soedinglab

CMAKE_ARGS+=	-DUSE_SYSTEM_ZSTD:BOOL=ON -DDISABLE_IPS4O:BOOL=ON
LDFLAGS+=	-lpthread

PLIST_FILES=	bin/mmseqs ${DATADIR}/bash-completion.sh

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" && empty(CFLAGS:M*march=native*)
# Need at least SSE2 for decent performance.  x86-64 groups SSE2 with other
# common features in low-end AMD64 CPUs.
CFLAGS+=	-march=x86-64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|MMSEQS_HOME/util|${DATADIR}|g' \
		${WRKSRC}/src/commons/Application.cpp

post-stage:
	${MV} ${STAGEDIR}${PREFIX}/util ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
