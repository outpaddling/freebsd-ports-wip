PORTNAME=	openkim
PORTVERSION=	1.7.1
CATEGORIES=	wip science
MASTER_SITES=	http://github.com/openkim/kim-api/archive/
DISTNAME=	v${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Knowledgebase of Interatomic Models
WWW=		https://openkim.org/

LICENSE=	CDDL

WRKSRC=		${WRKDIR}/kim-api-${PORTVERSION}

MAKE_ENV+=	KIM_DIR=${WRKSRC}
# Get this working with clang and gcc if possible
# MAKE_ENV+=	KIM_DYNAMIC=yes

USES=		gmake fortran
USE_GCC=	yes

# Is this downloading during build phase?
# BUILD_DEPENDS+=	git:devel/git

# Just for xxd command.  Use files/file2cinit instead.
# BUILD_DEPENDS+=	xxd:editors/vim

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.options.mk>

# Is there a better way to detect 32-bit systems?
.if ${ARCH} == "i386" || ${ARCH} == "powerpc"
MAKE_ENV+=	KIM_SYSTEM32="yes"
.endif

post-patch:
#	${REINPLACE_CMD} \
#		-e 's|xxd -i|${FILESDIR}/file2cinit|' \
#		${WRKSRC}/build_system/Makefile.ParameterizedModel \
#		${WRKSRC}/build_system/Makefile.Generic
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
	${CC} -o ${WRKSRC}/xxdi ${FILESDIR}/xxdi.c
	${REINPLACE_CMD} \
		-e 's|xxd -i|${WRKSRC}/xxdi|g' \
		${WRKSRC}/build_system/Makefile.Generic \
		${WRKSRC}/build_system/Makefile.ParameterizedModel

post-stage:
	${REINPLACE_CMD} -i '' -e 's|${STAGEDIR}||' \
		${STAGEDIR}${PREFIX}/lib/kim-api-v1/Makefile.KIM_Config
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/kim-api-v1/bin/kim-api-v1-descriptor-file-match
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/kim-api-v1/bin/kim-api-v1-build-config
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/kim-api-v1/libkim-api-v1.7.1-git+.GCC.linux.64bit.dynamic-load.so

.include <bsd.port.mk>
