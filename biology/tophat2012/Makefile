# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	tophat
PORTVERSION=	2.0.12
CATEGORIES=	biology science
# Note: Distfiles on Github are not the same as those here
MASTER_SITES=	http://ccb.jhu.edu/software/tophat/downloads/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Spliced read mapper for RNA-Seq

LICENSE=	BSL

# Compatible with bowtie 2.3.3: http://ccb.jhu.edu/software/tophat/index.shtml
# Is 2.2.7 OK?
BUILD_DEPENDS=	samtools01==0.1.19:/usr/wip/biology/samtools0119
LIB_DEPENDS+=	libboost_iostreams.so:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	bowtie2:/usr/wip/biology/bowtie2 \
		samtools01==0.1.19:/usr/wip/biology/samtools0119

# Hack to allow variable length arrays, which are not supported by ISO C++
USE_GCC=	yes
GNU_CONFIGURE=	yes
USES=		python shebangfix
SHEBANG_FILES=	src/tophat2.in

CFLAGS+=	-Wno-unused

CONFIGURE_ARGS+=	--with-bam=${LOCALBASE}/samtools0119

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
