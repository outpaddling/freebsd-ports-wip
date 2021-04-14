# $FreeBSD$

PORTNAME=	bedgraphtobigwig
DISTVERSION=	412
CATEGORIES=	wip biology
MASTER_SITES=	http://hgdownload.cse.ucsc.edu/admin/exe/userApps.archive/
DISTNAME=	userApps.v${PORTVERSION}.src

MAINTAINER=	bacon@moray.acadix.biz
COMMENT=	Convert a bedGraph file to bigWig format

# A lie.  Create custom license.
LICENSE=	BSD3CLAUSE
#LICENSE_FILE=	

USES=		gmake tar:tgz

WRKSRC=		${WRKDIR}/userApps

pre-build:
	cd ${WRKSRC} && bash ./fetchKentSource.sh

.include <bsd.port.mk>
