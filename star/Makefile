# $FreeBSD$

PORTNAME=	STAR
PORTVERSION=	2.7.0f
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	RNA-seq aligner

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/STAR-${PORTVERSION}/LICENSE

# 64-bit only
NOT_FOR_ARCHS=	i386 powerpc

USES=		compiler:openmp gmake
USE_GITHUB=	yes
GH_ACCOUNT=	alexdobin

# COMPILER_FEATURES+=	libc++
# to_string() issue with all gcc versions
# http://stackoverflow.com/questions/26832199/getting-gcc-in-c11-mode-to-work-on-freebsd
CXXFLAGS+=	-D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH -D_GLIBCXX_USE_C99_MATH_TR1
WRKSRC_SUBDIR=	source

PLIST_FILES=	bin/STAR

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/STAR ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
