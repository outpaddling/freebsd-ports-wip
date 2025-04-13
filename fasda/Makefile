PORTNAME=	fasda
DISTVERSION=	0.1.5-66
DISTVERSIONSUFFIX=	-g055baa8
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fast and simple differential analysis
WWW=		https://github.com/auerlab/fasda

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:wip/libxtend libbiolibc.so:wip/biolibc
RUN_DEPENDS=	stringtie>0:biology/stringtie

USES=		localbase
USE_GITHUB=	yes

GH_ACCOUNT=	auerlab

MAKE_ARGS=	MANPREFIX=${PREFIX}/share VERSION=${PORTVERSION}
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
