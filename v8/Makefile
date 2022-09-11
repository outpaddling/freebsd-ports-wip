# Created by: siasia

PORTNAME=	v8
DISTVERSION=	3.15.10
PORTEPOCH=	1
CATEGORIES=	wip lang
MASTER_SITES=	LOCAL/vanilla

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Google\'s open source JavaScript engine
WWW=		https://code.google.com/p/v8/

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=	amd64 i386

USES=		gmake python:2.7 tar:xz
USE_LDCONFIG=	yes
ALL_TARGET=	native

DISABLE_VULNERABILITIES=yes
MAKE_ARGS=	library=shared

#.if ${CC:T:Mclang} == "clang" || ${CXX:T:Mclang++} == "clang++" || ${OSVERSION} >= 1000024
MAKE_ENV+=	LINK=clang++
#.else
#MAKE_ARGS+=	strictaliasing=off
#USE_GCC=	any
#.endif

CFLAGS+=	-Wno-error

post-patch:
	@${REINPLACE_CMD} 's|/usr/bin/env python|${PYTHON_CMD}|g' \
		`fgrep -rl '/usr/bin/env python' work/v8-3.15.10`
	@${REINPLACE_CMD} 's|python -c|${PYTHON_CMD} -c|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/native/d8 ${STAGEDIR}${PREFIX}/bin/d8
	${INSTALL_LIB} -m 755 ${WRKSRC}/out/native/lib.target/libv8.so ${STAGEDIR}${PREFIX}/lib/libv8.so.1
	${RLN} ${STAGEDIR}${PREFIX}/lib/libv8.so.1 ${STAGEDIR}${PREFIX}/lib/libv8.so
	${INSTALL_DATA} ${WRKSRC}/include/v8.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-debug.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-preparser.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-profiler.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-testing.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8stdint.h ${STAGEDIR}${PREFIX}/include/

.include <bsd.port.mk>
