# $FreeBSD$

# FIXME: This is very basic.  Add support for more optimized builds
# including GPU support if possible.

PORTNAME=	FAMSA
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.4
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Algorithm for large-scale multiple sequence alignments

# Check this
LICENSE=	PD

LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd

USES=		gmake
USE_GCC=	yes		# Eliminate this
USE_GITHUB=	yes
GH_ACCOUNT=	refresh-bio

CXXFLAGS+=	-msse2
MAKEFILE=	makefile
# MAKE_JOBS_UNSAFE=	yes
PLIST_FILES=	bin/famsa

pre-build:
	${RM} ${WRKSRC}/libs-linux/*.a

.include <bsd.port.mk>
