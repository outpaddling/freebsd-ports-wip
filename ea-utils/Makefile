
PORTNAME=	ea-utils
PORTVERSION=	1.1.2
CATEGORIES=	wip biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
DISTNAME=	${PORTNAME}.${PORTVERSION}-806

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Command-line tools for processing fastq sequence data

LICENSE=	MIT

# Unbundled dependencies.  For build and run deps, specify the port name and
# minimum version, or a binary that it installs.
BUILD_DEPENDS=	samtools01==0.1.19:wip/samtools0119 \
		google-sparsehash>=2.0.2:devel/google-sparsehash
RUN_DEPENDS=	samtools01==0.1.19:wip/samtools0119 \
		R:math/R
# varcall.cpp calls GSL functions.  For library dependencies, specify the
# shared lib required.
LIB_DEPENDS=	libgsl.so:math/gsl

# Dist makefile uses GNU make extensions
USES=		gmake shebangfix
SHEBANG_FILES=	t/*.sh t/*.pl t/check-fastqs \
		determine-phred randomFQ alc

.include <bsd.port.pre.mk>

# Does not build with GCC 4.2
.if ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

CXXFLAGS+=	-I${LOCALBASE}/include -D_WITH_GETLINE

# For now, assume make shouldn't run multiple rules at once
MAKE_JOBS_UNSAFE=yes

post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin/Rscript|${LOCALBASE}/bin/Rscript|' \
		${WRKSRC}/fastx-graph

check:
	make build
	cd ${WRKSRC} && ${GMAKE} check

.include <bsd.port.post.mk>
