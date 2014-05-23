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

USES=		gmake perl5 shebangfix
SHEBANG_FILES=	trinity-plugins/collectl/make_data_files.sh \
		trinity-plugins/collectl/plot.sh \
		trinity-plugins/collectl/timetable.sh \
		util/*/*.sh \
		util/*/*.pl
# Requires OpenMP.  Use newer GCC for better optimizer.
USE_GCC=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.7 1.6

ONLY_FOR_ARCHS=	amd64

CFLAGS+=	-fopenmp
LDFLAGS+=	-fopenmp
MAKE_FLAGS+=	FORCE_UNSAFE_CONFIGURE=1

BUILD_DEPENDS+=	gsort:${PORTSDIR}/sysutils/coreutils
RUN_DEPENDS+=	gsort:${PORTSDIR}/sysutils/coreutils

MAKE_JOBS_UNSAFE=	yes

LIBEXEC_DIR=	${PREFIX}/libexec/trinity
PLUGINS_DIR=	${LIBEXEC_DIR}/trinity-plugins

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

# Some scripts are not available during patch stage
post-build:
	${REINPLACE_CMD} -i '' -e "s|/usr/bin/perl|${PREFIX}/bin/perl|g" \
		${WRKSRC}/trinity-plugins/collectl/bin/collectl \
		${WRKSRC}/trinity-plugins/collectl/bin/*.pl

# FIXME: Much more needs to be installed
# FIXME: Some of the 'plugins' should really be separate ports
#        Just dumping them to libexec/trinity for now
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Trinity ${STAGEDIR}${PREFIX}/bin

	${MKDIR} ${STAGEDIR}${LIBEXEC_DIR}/Chrysalis
	${INSTALL_PROGRAM} ${WRKSRC}/Chrysalis/Chrysalis \
		${STAGEDIR}${LIBEXEC_DIR}/Chrysalis

	${MKDIR} ${STAGEDIR}${LIBEXEC_DIR}/Inchworm/bin
	${INSTALL_PROGRAM} ${WRKSRC}/Inchworm/bin/* \
		${STAGEDIR}${LIBEXEC_DIR}/Inchworm/bin

	${MKDIR} ${STAGEDIR}${LIBEXEC_DIR}/Butterfly
	${INSTALL_SCRIPT} ${WRKSRC}/Butterfly/Butterfly.jar \
		${STAGEDIR}${LIBEXEC_DIR}/Butterfly

	cd ${WRKSRC} && ${COPYTREE_BIN} PerlLib \
		${STAGEDIR}${LIBEXEC_DIR}

	cd ${WRKSRC} && ${COPYTREE_BIN} util \
		${STAGEDIR}${LIBEXEC_DIR}

	${MKDIR} ${STAGEDIR}${PLUGINS_DIR}/jellyfish
	${STRIP_CMD} ${WRKSRC}/trinity-plugins/jellyfish/bin/.libs/jellyfish \
		${WRKSRC}/trinity-plugins/jellyfish/.libs/libjellyfish-1.1.so.1
	cd ${WRKSRC}/trinity-plugins/jellyfish && \
		${COPYTREE_BIN} 'bin .libs' ${STAGEDIR}${PLUGINS_DIR}/jellyfish

	${MKDIR} ${STAGEDIR}${PLUGINS_DIR}/fastool
	${INSTALL_PROGRAM} ${WRKSRC}/trinity-plugins/fastool/fastool \
		${STAGEDIR}${PLUGINS_DIR}/fastool

	${MKDIR} ${STAGEDIR}${PLUGINS_DIR}/collectl
	cd ${WRKSRC}/trinity-plugins/collectl && \
		${COPYTREE_BIN} bin ${STAGEDIR}${PLUGINS_DIR}/collectl

	${MKDIR} ${STAGEDIR}${PLUGINS_DIR}/coreutils
	cd ${WRKSRC}/trinity-plugins/coreutils && \
		${COPYTREE_BIN} bin ${STAGEDIR}${PLUGINS_DIR}/coreutils

	${MKDIR} ${STAGEDIR}${PLUGINS_DIR}/parafly/bin
	${INSTALL_PROGRAM} ${WRKSRC}/trinity-plugins/parafly/bin/ParaFly \
		${STAGEDIR}${PLUGINS_DIR}/parafly/bin

	${MKDIR} ${STAGEDIR}${PLUGINS_DIR}/Trimmomatic

	cd ${WRKSRC}/trinity-plugins/Trimmomatic && \
		${COPYTREE_BIN} "adapters trimmomatic*.jar" \
		${STAGEDIR}${PLUGINS_DIR}/Trimmomatic

	cd ${WRKSRC}/sample_data && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
