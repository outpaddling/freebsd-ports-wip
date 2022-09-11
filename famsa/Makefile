# FIXME: This is very basic.  Add support for more optimized builds
# including GPU support if possible.

PORTNAME=	FAMSA
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.4
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Algorithm for large-scale multiple sequence alignments
WWW=		https://github.com/refresh-bio/FAMSA

# Check this
LICENSE=	PD

LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd

USES=		gmake
USE_GCC=	yes		# Eliminate this
USE_GITHUB=	yes
GH_ACCOUNT=	refresh-bio

# See workaround.hpp.  Uses memset to zero floating point variables.
# Possibly for non-x86: -DBOOST_CONTAINER_MEMZEROED_FLOATING_POINT_IS_NOT_ZERO
CFLAGS_i386+=	-msse2
MAKEFILE=	makefile
PLIST_FILES=	bin/famsa

pre-build:
	${RM} ${WRKSRC}/libs-linux/*.a

.include <bsd.port.mk>
