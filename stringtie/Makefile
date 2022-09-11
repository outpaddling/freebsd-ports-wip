PORTNAME=	stringtie
PORTVERSION=	1.3.4d
DISTVERSIONPREFIX=v
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org.edu
COMMENT=	Transcript assembly and quantification for RNA-Seq
WWW=		https://www.ccb.jhu.edu/software/stringtie/

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake

USE_GITHUB=	yes
USE_GCC=	yes
GH_ACCOUNT=	gpertea

MAKE_JOBS_UNSAFE=	yes
# FIXME: Other targets clobber CXXFLAGS
ALL_TARGET=	release
PLIST_FILES=	bin/stringtie

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stringtie ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
