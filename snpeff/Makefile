PORTNAME=	snpeff
DISTVERSIONPREFIX=	v
DISTVERSION=	5.4a
CATEGORIES=	wip biology java python

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Genetic variant annotation and effect prediction toolbox
WWW=		https://github.com/pcingola/SnpEff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	mvn:devel/maven
RUN_DEPENDS=	bash:shells/bash

USES=		java python:3.6+ shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	pcingola
GH_PROJECT=	SnpEff
JAVA_VERSION=	17+
SHEBANG_FILES=	scripts/* scripts/gsa/*

# NO_ARCH=	yes

LIBEXEC_DIR=	${PREFIX}/libexec/snpeff

pre-configure:
	${REINPLACE_CMD} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g' \
			 -e 's|%%JAVA_HOME%%|${JAVA_HOME}|g' \
			 ${WRKSRC}/scripts/snpEff ${WRKSRC}/scripts/snpSift

MAVEN_ENV=      MAVEN_OPTS=-Xmx2048m CC=${CC} CFLAGS="${CFLAGS}" JAVA_HOME=${JAVA_HOME}

# To make the build working, set the (maven) architecture to x86_64 instead of amd64
# Finally there are problems with amd64
MAVEN_ARCH=     ${ARCH:S|amd64|x86_64|}

MAVEN_PARAMS=   --offline \
                -Dnative=gtk.freebsd.${MAVEN_ARCH} \
                -DskipTests clean verify

#.if ${COMPILER_TYPE} == clang
#CFLAGS+=        -Wno-deprecated-non-prototype
#.endif
                        
do-build:
	cd ${WRKSRC} && ${SETENV} ${MAVEN_ENV} mvn ${MAVEN_PARAMS}

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}/snpeff
	${MKDIR} ${STAGEDIR}${LIBEXEC_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/snpEff ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/snpSift ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.jar ${STAGEDIR}${JAVAJARDIR}/snpeff
	${INSTALL_DATA} ${WRKSRC}/*.config ${STAGEDIR}${JAVAJARDIR}/snpeff
	cd ${WRKSRC}/scripts && ${COPYTREE_BIN} . ${STAGEDIR}${LIBEXEC_DIR}

.include <bsd.port.mk>
