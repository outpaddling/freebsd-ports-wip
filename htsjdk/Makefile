PORTNAME=	htsjdk
PORTVERSION=	2.6.1
CATEGORIES=	wip biology

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Generic format for storing large nucleotide sequence alignments
WWW=		https://example.com

# LICENSE actually varies
LICENSE=	BSD2CLAUSE

USE_JAVA=	1.8

USE_GITHUB=	yes
GH_ACCOUNT=	samtools

BUILD_DEPENDS=	gradle:devel/gradle

MAKE_ENV=	JAVA_HOME=${JAVA_HOME}

# http://samtools.github.io/htsjdk/building.html#BuildingHtsJdk
do-build:
	cd ${WRKSRC} && gradle

test:
	cd ${WRKSRC} && gradle test

do-install:
	cd ${WRKSRC}/dist && ${COPYTREE_SHARE} . \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}

.include <bsd.port.mk>
