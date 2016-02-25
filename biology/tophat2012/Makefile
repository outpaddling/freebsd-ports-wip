# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	tophat
PORTVERSION=	2.0.12
CATEGORIES=	biology science
MASTER_SITES=	http://ccb.jhu.edu/software/tophat/downloads/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Spliced read mapper for RNA-Seq

LICENSE=	ClArtistic

BUILD_DEPENDS=	samtools01==0.1.19:/usr/wip/biology/samtools0119
LIB_DEPENDS+=	libboost_iostreams.so:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	bowtie:/usr/wip/biology/bowtie \
		samtools01==0.1.19:/usr/wip/biology/samtools0119

# Hack to allow variable length arrays, which are not supported by ISO C++
USE_GCC=	yes
GNU_CONFIGURE=	yes
USES=		python shebangfix
SHEBANG_FILES=	src/tophat2.in

CFLAGS+=	-Wno-unused

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
