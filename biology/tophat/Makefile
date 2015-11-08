# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	tophat
PORTVERSION=	2.0.11
CATEGORIES=	biology science
MASTER_SITES=	http://ccb.jhu.edu/software/tophat/downloads/

MAINTAINER=	jwbacon@tds.net
COMMENT=	A spliced read mapper for RNA-Seq

# Hack to allow variable length arrays, which are not supported by ISO C++
USE_GCC=	yes
GNU_CONFIGURE=	yes
USES=		python shebangfix
SHEBANG_FILES=	src/tophat2.in

BUILD_DEPENDS=	${LOCALBASE}/lib/libbam.a:/usr/wip/biology/samtools
LIB_DEPENDS+=	libboost_iostreams.so:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	bowtie:/usr/wip/biology/bowtie

CFLAGS+=	-Wno-unused

# MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
