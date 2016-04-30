# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rstudio
DISTVERSION=	v0.98.490
CATEGORIES=	devel java
MASTER_SITES+=	https://s3.amazonaws.com/rstudio-dictionaries/:dictionaries \
    		https://s3.amazonaws.com/rstudio-buildtools/:buildtools \
		http://mirrors.rit.edu/zi/:DEFAULT,dictionaries,buildtools
DISTFILES+=	${DISTVERSION}.tar.gz \
		mathjax-${JAXVER}.zip:buildtools \
		gwt-${GWTVER}.zip:buildtools \
		gin-${GINVER}.zip:buildtools \
		core-dictionaries.zip:dictionaries
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTVERSION}.tar.gz gwt-${GWTVER}.zip

MAINTAINER=	zi@FreeBSD.org
COMMENT=	The premier integrated development environment for R

LICENSE=	AGPLv3

EXTRACT_DEPENDS=unzip>0:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	${LOCALBASE}/bin/R:${PORTSDIR}/math/R
BUILD_DEPENDS=	${LOCALBASE}/bin/R:${PORTSDIR}/math/R \
    		ant:${PORTSDIR}/devel/apache-ant
LIB_DEPENDS=	libboost_system.so:${PORTSDIR}/devel/boost-libs \
    		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libinotify.so:${PORTSDIR}/devel/libinotify

USE_GITHUB=	yes
GH_ACCOUNT=	rstudio
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${DISTVERSION}
GH_COMMIT=	79af91e

GINVER=		1.5
GWTVER=		2.5.1
JAXVER=		20

USE_GCC=	yes
USE_FORTRAN=	yes
USE_JAVA=	yes
JAVA_BUILD=	yes
USES=		cmake:outsource
CMAKE_ARGS+=	-DRSTUDIO_TARGET=Server -DCMAKE_BUILD_TYPE=Release \
		-DRSTUDIO_INSTALL_SUPPORTING=${PREFIX}/lib \
		-DRSTUDIO_INSTALL_BIN=${PREFIX}/sbin
NO_STAGE=	yes

GINFILES=	LICENSE README aopalliance.jar gin-${GINVER}-post-gwt-2.2.jar \
		gin-${GINVER}-pre-gwt-2.2.jar guice-assistedinject-snapshot.jar \
		guice-snapshot.jar javadoc javax.inject.jar
DICTIONARIES=	en_AU.aff en_AU.dic en_AU.dic_delta en_CA.aff en_CA.dic \
		en_CA.dic_delta en_GB.aff en_GB.dic en_GB.dic_delta \
		en_US.aff en_US.dic en_US.dic_delta

post-extract:
	@${MKDIR} ${WRKSRC}/src/gwt/lib/gin ${WRKSRC}/src/gwt/lib/gwt
	@${LN} -sf ${WRKDIR}/gwt-${GWTVER} ${WRKSRC}/src/gwt/lib/gwt/${GWTVER}
	@${UNZIP_CMD} -qo -d ${WRKSRC}/dependencies/common \
	    	${_DISTDIR}/mathjax-${JAXVER}.zip
	@${UNZIP_CMD} -qo -d ${WRKSRC}/dependencies/common/dictionaries \
	    	${_DISTDIR}/core-dictionaries.zip
	@${UNZIP_CMD} -qo -d ${WRKSRC}/src/gwt/lib/gin/${GINVER} \
	    	${_DISTDIR}/gin-${GINVER}.zip

.include <bsd.port.mk>
