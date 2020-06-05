# $FreeBSD$

PORTNAME=	picard
PORTVERSION=	2.22.9
CATEGORIES=	wip biology java
MASTER_SITES=	http://github.com/broadinstitute/picard/releases/download/${PORTVERSION}/
PKGNAMESUFFIX=	-tools
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.jar

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	CLI tools for manipulating high-throughput sequencing (HTS) data

LICENSE=	MIT

RUN_DEPENDS=	samtools:biology/samtools

USE_JAVA=	1.8+
JAVA_RUN=	yes

NO_BUILD=	yes

PLIST_FILES=	${JAVAJARDIR}/picard.jar

do-extract:
	# No extract

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.mk>
