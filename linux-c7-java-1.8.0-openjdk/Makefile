# Created by: Piotr Kubaj <pkubaj@anongoth.pl>

PORTNAME=	java-1.8.0-openjdk
PORTVERSION=	1.8.0.242.b08
DISTVERSIONSUFFIX=	-1.el7
CATEGORIES=	wip java

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	OpenJDK

# ??
LICENSE=	LGPL21+

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*
DESCR=		${.CURDIR}/../../java/openjdk8/pkg-descr

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
