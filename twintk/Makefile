# Created by: Jason Bacon <jwb@FreeBSD.org>

PORTNAME=	twintk
DISTVERSION=	0.9.4-16
DISTVERSIONSUFFIX=	-gb6b09d8
CATEGORIES=	wip devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Misc functions

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libxtend.so:wip/libxtend

.include <bsd.port.pre.mk>

# DragonFly and NetBSD make don't handle source subdirectories
# See if this can be fixed upstream
.if ${OPSYS} == DragonFly
USES=		gmake
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

.include <bsd.port.post.mk>
