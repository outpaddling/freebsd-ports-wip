# $FreeBSD$

PORTNAME=	tophat
DISTVERSION=	2.1.1
CATEGORIES=	wip biology science
MASTER_SITES=	http://ccb.jhu.edu/software/tophat/downloads/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fast splice junction mapper for RNA-Seq reads

LICENSE=	BSL

LIB_DEPENDS+=	libboost_iostreams.so:devel/boost-libs
RUN_DEPENDS=	bowtie2:biology/bowtie2

USES=		gmake python shebangfix

SHEBANG_FILES=	src/contig_to_chr_coords src/bed_to_juncs \
		src/sra_to_solid src/tophat-fusion-post \
		src/tophat.py src/tophat2.sh

GNU_CONFIGURE=	yes
CFLAGS+=	-Wno-unused
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
