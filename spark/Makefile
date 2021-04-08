PORTNAME=	spark
PORTVERSION=	1.1.0
CATEGORIES=	wip sysutils
MASTER_SITES=	http://d3kbcqa49mib13.cloudfront.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fast and general-purpose cluster computing system

BUILD_DEPENDS+=	scala:lang/scala \
		${LOCALBASE}/share/java/maven31/bin/mvn:devel/maven31

BUILD_ENV+=	MAVEN_OPTS="-Xmx2g -XX:MaxPermSize=512M -XX:ReservedCodeCacheSize=512m"

do-build:
	cd ${WRKSRC} && mvn -Pyarn -Phadoop-2.4 -Dhadoop.version=2.4.1 -DskipTests clean package

.include <bsd.port.mk>
