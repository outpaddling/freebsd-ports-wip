# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	globus_toolkit
PORTVERSION=	6.0.1453307864
CATEGORIES=	net
MASTER_SITES=	http://toolkit.globus.org/ftppub/gt6/installers/src/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Open source software toolkit used for building grids

GNU_CONFIGURE=	yes

# http://toolkit.globus.org/toolkit/docs/4.0/admin/docbook/ch03.html#s-prereq-required
# gtar? gsed? gmake? JDBC compliant database. For instance, PostgreSQL 7.1+
# gpt-3.2autotools2004 (shipped with the installers, but required if building standalone GPT bundles/packages)
LIB_DEPENDS=	libltdl.so:devel/libltdl
BUILD_DEPENDS=	openssl>=1.0:security/openssl \
		ant:devel/apache-ant
RUN_DEPENDS=	openssl>=1.0:security/openssl

USES=		perl5
USE_JAVA=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
