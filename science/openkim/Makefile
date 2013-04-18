# Created by:	Jason Bacon
# $FreeBSD$

PORTNAME=	openkim
PORTVERSION=	1.1.1
CATEGORIES=	science
MASTER_SITES=	http://s3.openkim.org/
DISTNAME=	${PORTNAME}-api-v${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jwbacon@tds.net
COMMENT=	Knowledgebase of Interatomic Models

LICENSE=	CDDL

MAKE_ENV+=	KIM_DIR=${WRKSRC}

USE_GMAKE=	yes
USE_FORTRAN=	yes

.include <bsd.port.options.mk>

# Is there a better way to detect 32-bit systems?
.if ${ARCH} == "i386" || ${ARCH} == "powerpc"
MAKE_ENV+=	KIM_SYSTEM32="yes"
.endif

post-patch:
	${REINPLACE_CMD} \
		-e "s|gcc|${CC}|g" \
		-e "s|g++|${CXX}|g" \
		-e "s|= gfortran|= ${FC}|g" \
		-e "s|-O3|-O2|g" \
		-e "s|LINKLIBFLAG =|LINKLIBFLAG = -Wl,-rpath=${LOCALBASE}/lib/${_GCC_BUILD_DEPENDS}|g" \
		${WRKSRC}/KIM_API/GNU_compiler_settings.mk

# Required for main build to succeed
pre-build:
	(cd ${WRKSRC} && ${GMAKE} KIM_DIR=${WRKSRC} examples)

do-install:
	${MKDIR} ${PREFIX}/lib ${PREFIX}/include/KIM_API
	${INSTALL_DATA} ${WRKSRC}/KIM_API/libkim.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/KIM_API/*.h ${PREFIX}/include/KIM_API

.include <bsd.port.mk>
