# Created by: Jason Bacon <jwb@FreeBSD.org>
# $FreeBSD: head/lang/x10/Makefile 386097 2015-05-11 18:34:57Z mat $

PORTNAME=	x10
PORTVERSION=	2.5.3
CATEGORIES=	wip lang devel java
MASTER_SITES=	http://x10-lang.org/dependencies/ \
      		http://central.maven.org/maven2/org/xerial/snappy/snappy-java/1.1.2-RC2/ \
		SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		lpg.runtime.java_2.0.22.jar \
		antlr-runtime_4.5.0.201505151407.jar \
		ecj-4.4.2.jar \
		hazelcast-3.3.1.jar \
		com.ibm.wala.cast.java_1.0.0.201101071300.jar \
		com.ibm.wala.cast_1.0.0.201101071300.jar \
		com.ibm.wala.core_1.1.3.201101071300.jar \
		com.ibm.wala.shrike_1.3.1.201101071300.jar \
		org.eclipse.equinox.common_3.6.0.v20100503.jar \
		commons-math3-3.5.jar \
		commons-logging-1.2.jar \
		snappy-java-1.1.2-RC2.jar
		# bdwgc-7.1.tar.gz

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Object-oriented parallel programming language

LICENSE=	EPL

USES=	tar:bzip2
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
USE_GCC=	yes

USE_LDCONFIG=	${PREFIX}/stdlib/lib

# Can't have USE_GMAKE with USE_ANT: They imply conflicting do-build actions.
BUILD_DEPENDS+=	gmake:devel/gmake \
		bash:shells/bash

WRKSRC=		${WRKDIR}/x10.dist

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's/value="make"/value="gmake"/g' \
		${WRKDIR}/x10.runtime/build.xml
	${MKDIR} ${WRKSRC}/lib ${WRKDIR}/x10.runtime/src-cpp/bdwgc/src
	${CP} ${DISTDIR}/lpg.runtime.java_2.0.22.jar ${WRKSRC}/lib/lpg.jar
	${CP} ${DISTDIR}/ecj-4.4.2.jar ${WRKSRC}/lib/ecj.jar
	${CP} ${DISTDIR}/hazelcast-3.3.1.jar ${WRKSRC}/lib
	${CP} ${DISTDIR}/com.ibm.wala.cast.java_1.0.0.201101071300.jar ${WRKSRC}/lib
	${CP} ${DISTDIR}/com.ibm.wala.cast_1.0.0.201101071300.jar ${WRKSRC}/lib
	${CP} ${DISTDIR}/com.ibm.wala.core_1.1.3.201101071300.jar ${WRKSRC}/lib
	${CP} ${DISTDIR}/com.ibm.wala.shrike_1.3.1.201101071300.jar ${WRKSRC}/lib
	${CP} ${DISTDIR}/org.eclipse.equinox.common_3.6.0.v20100503.jar ${WRKSRC}/lib
	${CP} ${DISTDIR}/commons-math3-3.5.jar ${WRKSRC}/lib
#	${CP} ${DISTDIR}/bdwgc-7.1.tar.gz ${WRKDIR}/x10.runtime/src-cpp/bdwgc
#	(cd ${WRKDIR}/x10.runtime/src-cpp/bdwgc/src && tar zxvf ../bdwgc-7.1.tar.gz && ${REINPLACE_CMD} -e 's|freebsd1\*|freebsd1.*|g' configure)

do-install:
.for f in X10Launcher apgas precommit x10 x10c x10c++ x10j
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/stdlib
	${INSTALL_DATA} ${WRKSRC}/etc/* ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/include/* ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${PREFIX}/lib
	${CP} -R ${WRKSRC}/stdlib/* ${STAGEDIR}${PREFIX}/stdlib
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/samples/* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
