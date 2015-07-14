# Created by: Jason Wayne Bacon <bacon@sciprog.ceas.uwm.edu>
# $FreeBSD$

PORTNAME=	picard
PORTVERSION=	1.133
CATEGORIES=	biology
MASTER_SITES=	https://github.com/broadinstitute/picard/archive/
PKGNAMESUFFIX=	-tools
DISTNAME=	${PORTVERSION}
# Same distname as htsjdk
DIST_SUBDIR=	picard

MAINTAINER=	bacon@sciprog.ceas.uwm.edu
COMMENT=

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

BUILD_DEPENDS=	${ANT_CMD}:${PORTSDIR}/devel/apache-ant

.include <bsd.port.mk>
