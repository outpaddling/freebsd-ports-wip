# $FreeBSD$

PORTNAME=	abyss
PORTVERSION=	2.1.0
CATEGORIES=	wip

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Assemble large genomes using short reads

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	sparsehash>0:devel/sparsehash
LIB_DEPENDS=	libmpi.so:net/openmpi \
		libboost_system.so:devel/boost-libs
USES=		autoreconf compiler:openmp shebangfix sqlite
SHEBANG_FILES=	bin/abyss-bowtie bin/abyss-bowtie2 bin/abyss-bwa \
		bin/abyss-bwasw bin/abyss-bwamem bin/abyss-kaligner \
		bin/abyss-pe bin/abyss-bloom-dist.mk bin/abyss-dida

GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	bcgsc

CXXFLAGS+=	-DHAVE_LIBDL=1
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
