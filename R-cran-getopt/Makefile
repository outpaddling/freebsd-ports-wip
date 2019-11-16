# $FreeBSD$

PORTNAME=	getopt
DISTVERSION=	1.20.3
CATEGORIES=	wip devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Used with Rscript to write scripts that accept short and long flags

# 2 or 3
LICENSE=	GPLv2
#LICENSE_FILE=	

USES=		cran

post-patch:
	@${REINPLACE_CMD} -i '' -e \
		's|/path/to/Rscript|${LOCALBASE}/bin/Rscript|' \
		${WRKSRC}/exec/example.R

.include <bsd.port.mk>
