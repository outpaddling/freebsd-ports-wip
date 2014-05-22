# New ports collection makefile for:	trinity
# Date created:		2013-05-22
# Whom:			Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	trinity
PORTVERSION=	2014.04.13
CATEGORIES=	biology
MASTER_SITES=	https://sourceforge.net/projects/trinityrnaseq/files/
DISTNAME=	trinityrnaseq_r20140413p1

MAINTAINER=	jwbacon@tds.net
COMMENT=	RNA sequence assembly

USE_GMAKE=	yes
# Requires OpenMP
USE_GCC=	any
USE_JAVA=	yes

ONLY_FOR_ARCHS=	amd64

CFLAGS+=	-fopenmp
LDFLAGS+=	-fopenmp
MAKE_FLAGS+=	FORCE_UNSAFE_CONFIGURE=1

BUILD_DEPENDS+=	gsort:${PORTSDIR}/sysutils/coreutils
RUN_DEPENDS+=	gsort:${PORTSDIR}/sysutils/coreutils

MAKE_JOBS_UNSAFE=	yes

post-patch:
	${REINPLACE_CMD} -e "s|gcc|${CC}|g" -e "s|g++|${CXX}|g" \
		${WRKSRC}/Makefile \
		${WRKSRC}/Chrysalis/Makefile* \
		${WRKSRC}/trinity-plugins/fastool/Makefile \
		${WRKSRC}/trinity-plugins/slclust/src/Makefile
.if exists(/usr/lib/libexecinfo.so)
	${REINPLACE_CMD} -e "s|configure CC=${CC} CXX=${CXX}|configure CC=${CC} CXX=${CXX} LDFLAGS=-lexecinfo|g" ${WRKSRC}/Makefile
.endif
	${MV} ${WRKSRC}/Chrysalis/Makefile_g++ \
		${WRKSRC}/Chrysalis/Makefile_${CXX}
	${MV} ${WRKSRC}/Chrysalis/Makefile_g++_x86_64 \
		${WRKSRC}/Chrysalis/Makefile_${CXX}_x86_64
	${MV} ${WRKSRC}/Chrysalis/Makefile_g++_i386 \
		${WRKSRC}/Chrysalis/Makefile_${CXX}_i386
	${REINPLACE_CMD} \
		-e 's|/bin/bash|/usr/bin/env bash|g' \
		-e 's|make |${GMAKE} |g' \
		-e 's|sort |gsort |g' \
		${WRKSRC}/trinity-plugins/coreutils/build_parallel_sort.sh \
		${WRKSRC}/trinity-plugins/collectl/build_collectl.sh
	${REINPLACE_CMD} \
		-e "s|Bin/PerlLib|Bin/../share/trinity/PerlLib|" ${WRKSRC}/Trinity

#		-e "s|use HTC::GridRunner;|use lib ${DATADIR}/PerlLib; use HTC::GridRunner;|" ${WRKSRC}/Trinity

# FIXME: Much more needs to be installed
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Chrysalis/Chrysalis \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/Inchworm/bin/* \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/trinity-plugins/jellyfish/bin/.libs/jellyfish \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/trinity-plugins/jellyfish/bin/jellyfish \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Trinity ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Butterfly/Butterfly.jar \
		${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/sample_data && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC} && ${COPYTREE_SHARE} PerlLib \
		${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
