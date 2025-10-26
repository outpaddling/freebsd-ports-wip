PORTNAME=	orthanc-dicomweb
DISTVERSION=	1.21
CATEGORIES=	wip science
MASTER_SITES=	https://orthanc.uclouvain.be/downloads/sources/orthanc-dicomweb/ \
		https://orthanc.uclouvain.be/downloads/third-party-downloads/ \
		https://orthanc.uclouvain.be/downloads/third-party-downloads/dicom-web/ \
		https://orthanc.uclouvain.be/downloads/sources/orthanc/
DISTNAME=	OrthancDicomWeb-${PORTVERSION}
EXTRADISTFILES=	Orthanc-${ORTHANC_VER}.tar.gz \
		e2fsprogs-1.44.5.tar.gz \
		bootstrap-5.3.3.zip \
		vuejs-2.6.10.tar.gz \
		axios-0.19.0.tar.gz \
		Font-Awesome-4.7.0.tar.gz \
		babel-polyfill-6.26.0.min.js.gz \
		bootstrap-vue-2.0.0-rc.24-dist.tar.gz
DISTFILES+=	${EXTRADISTFILES}
DIST_SUBDIR=	orthanc
EXTRACT_ONLY=	OrthancDicomWeb-${PORTVERSION}.tar.gz

MAINTAINER=	maintainer.freebsd@xpoundit.com
COMMENT=	Orthanc plugin to bring support of the DICOMweb standard into Orthanc
WWW=		https://www.orthanc-server.com/static.php?page=dicomweb

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	orthanc>=${ORTHANC_VER}:science/orthanc
LIB_DEPENDS=	libboost_atomic.so:devel/boost-libs \
		libjsoncpp.so:devel/jsoncpp \
		libpugixml.so:textproc/pugixml
RUN_DEPENDS=	Orthanc:science/orthanc

USES=		cmake localbase python:build
USE_LDCONFIG=	share/orthanc/plugins

ORTHANC_VER=	1.12.9
CMAKE_ARGS=	-DORTHANC_FRAMEWORK_ROOT=${WRKSRC}/ThirdPartyDownloads/Orthanc-${ORTHANC_VER}/OrthancFramework/Sources \
		-DORTHANC_FRAMEWORK_SOURCE=path
CMAKE_OFF=	USE_SYSTEM_UUID

CFLAGS+=	-DORTHANC_ENABLE_LOGGING_PLUGIN -DNDEBUG
CXXFLAGS+=	-DNDEBUG

WRKSRC=		${WRKDIR}/OrthancDicomWeb-${PORTVERSION}

PLIST_SUB=	DISTVERSION=${DISTVERSION}

post-extract:
	${MKDIR} ${WRKSRC}/ThirdPartyDownloads
.for f in ${EXTRADISTFILES:C/:[^:]*//}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${f} ${WRKSRC}/ThirdPartyDownloads
.endfor
	${TAR} -C ${WRKSRC}/ThirdPartyDownloads -xf ${WRKSRC}/ThirdPartyDownloads/Orthanc-${ORTHANC_VER}.tar.gz

do-test:
	@cd ${BUILD_WRKSRC} && ./UnitTests

.include <bsd.port.mk>
