# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	ea-utils
PORTVERSION=	1.1.2
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
DISTNAME=	${PORTNAME}.${PORTVERSION}-806

MAINTAINER=	jwbacon@tds.net
COMMENT=	Command-line tools for processing fastq sequence data

# Dist makefile uses GNU make extensions
USES=		gmake shebangfix
SHEBANG_FILES=	t/*.sh t/*.pl t/check-fastqs

# varcall.cpp calls GSL functions.  For library dependencies, specify the
# shared lib required.
LIB_DEPENDS=	libgsl.so:${PORTSDIR}/math/gsl

# Unbundled dependencies.  For build and run deps, specify the port name and
# minimum version, or a binary that it installs.
BUILD_DEPENDS=	samtools>=0.1.19:/usr/wip/biology/samtools \
		google-sparsehash>=2.0.2:${PORTSDIR}/devel/google-sparsehash
RUN_DEPENDS=	${BUILD_DEPENDS}

CXXFLAGS+=	-I${LOCALBASE}/include -D_WITH_GETLINE

# For now, assume make shouldn't run multiple rules at once
MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
