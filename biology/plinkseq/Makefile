# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD: head/biology/plinkseq/Makefile 369969 2014-10-04 15:12:44Z sunpoet $

PORTNAME=	plinkseq
PORTVERSION=	0.10
CATEGORIES=	biology science
MASTER_SITES=	http://psychgen.u.hpc.mssm.edu/plinkseq_downloads/
DISTFILES=	${PORTNAME}-src-${PORTVERSION}.tgz

MAINTAINER=	jwbacon@tds.net
COMMENT=	Toolset for working with human genetic variation data

LICENSE=	GPLv2

USES=		dos2unix libtool shebangfix gmake
USE_LDCONFIG=	yes

# MAKE_JOBS_UNSAFE=yes

post-patch:
	${REINPLACE_CMD} -e 's|PF_INET|AF_INET|g' \
		${WRKSRC}/sources/mongoose/sources/lib/mongoose.c
	${REINPLACE_CMD} \
		-e 's|g++|${CXX}|g' \
		-e 's|gcc|${CC}|g' \
		-e 's|CXXFLAGS = -O3|CXXFLAGS = ${CXXFLAGS}|g' \
		-e 's|ALL_CFLAGS =-O3|ALL_CFLAGS = ${CFLAGS}|g' \
		${WRKSRC}/config_defs.Makefile
	${REINPLACE_CMD} \
		-e 's| -ldl||g' \
		-e 's| $$(STATIC_FLAG)||g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/execs/behead \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/execs/browser \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/execs/gcol \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/execs/mm \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/execs/mongoose \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/execs/pdas \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/execs/pseq \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/execs/smp \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/execs/tab2vcf \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sources/plinkseq/build/lib/libplinkseq.a \
		${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
