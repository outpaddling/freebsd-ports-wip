PORTNAME=	twintk
DISTVERSION=	0.9.4-31
DISTVERSIONSUFFIX=	-gda7813f
CATEGORIES=	wip devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Terminal Windows Took Kit
WWW=		https://github.com/outpaddling/twintk

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libxtend.so:wip/libxtend

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

WITH_DEBUG=	yes

.include <bsd.port.options.mk>

# DragonFly and NetBSD make don't handle source subdirectories
# See if this can be fixed upstream
.if ${OPSYS} == DragonFly
USES+=		gmake
.endif

.include <bsd.port.mk>
