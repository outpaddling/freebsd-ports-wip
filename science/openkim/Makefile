# Created by: Jason Bacon
# $FreeBSD: head/science/openkim/Makefile 345491 2014-02-21 15:39:56Z thierry $

PORTNAME=	openkim
PORTVERSION=	1.7.1
CATEGORIES=	science
MASTER_SITES=	http://github.com/openkim/kim-api/archive/
DISTNAME=	v${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Knowledgebase of Interatomic Models

LICENSE=	CDDL

WRKSRC=		${WRKDIR}/kim-api-${PORTVERSION}

MAKE_ENV+=	KIM_DIR=${WRKSRC}
# Get this working with clang and gcc if possible
# MAKE_ENV+=	KIM_DYNAMIC=yes

USES=		gmake fortran
USE_GCC=	yes

# Is this downloading during build phase?
# BUILD_DEPENDS+=	git:${PORTSDIR}/devel/git

# Just for xxd command.  Figure out how to use hexdump instead.
BUILD_DEPENDS+=	xxd:${PORTSDIR}/editors/vim

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.options.mk>

# Is there a better way to detect 32-bit systems?
.if ${ARCH} == "i386" || ${ARCH} == "powerpc"
MAKE_ENV+=	KIM_SYSTEM32="yes"
.endif

post-patch:
	${MV} ${WRKSRC}/Makefile.KIM_Config.example \
		${WRKSRC}/Makefile.KIM_Config
	${REINPLACE_CMD} \
		-e 's|^KIM_DIR.*$$|KIM_DIR = ${WRKSRC}|' \
		${WRKSRC}/Makefile.KIM_Config
	${REINPLACE_CMD} \
		-e "s|gcc|${CC}|g" \
		-e "s|g++|${CXX}|g" \
		-e "s|= gfortran|= ${FC}|g" \
		-e "s|-O3|${CFLAGS}|g" \
		-e 's|LDFLAGS *=|LDFLAGS = ${LDFLAGS}|g' \
		-e 's|-ldl||g' \
		${WRKSRC}/build_system/compiler_defaults/Makefile.GCC

post-stage:
	${REINPLACE_CMD} -i '' -e 's|${STAGEDIR}||' \
		${STAGEDIR}${PREFIX}/lib/kim-api-v1/Makefile.KIM_Config
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/kim-api-v1/bin/kim-api-v1-descriptor-file-match
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/kim-api-v1/bin/kim-api-v1-build-config
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/kim-api-v1/libkim-api-v1.7.1-git+.GCC.linux.64bit.dynamic-load.so

.include <bsd.port.mk>
