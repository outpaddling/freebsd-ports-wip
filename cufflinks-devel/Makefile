# This version is known to crash frequently

PORTNAME=	cufflinks
PORTVERSION=	2.2.1
CATEGORIES=	wip biology
MASTER_SITES=	http://cole-trapnell-lab.github.io/cufflinks/assets/downloads/
# Switch to USE_GITHUB?

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Transcript assembly, differential expression and regulation for RNA-Seq
WWW=		https://port.home.page/

LICENSE=	BSL

USES=		python
GNU_CONFIGURE=	yes

BUILD_DEPENDS=	samtools01==0.1.19:wip/samtools0119 \
		bjam:devel/boost-jam \
		eigen>3:math/eigen3
LIB_DEPENDS+=	libboost_iostreams.so:devel/boost-libs
RUN_DEPENDS=	samtools01==0.1.19:wip/samtools0119

CONFIGURE_ARGS+=--with-bam=${LOCALBASE}/samtools0119

CFLAGS+=	-I${LOCALBASE}/include/eigen3 \
		-Wno-unused -Wno-reorder -Wno-sign-compare

MAKE_JOBS_UNSAFE=yes

# FIXME: boost problem with long double and hackaround: https://svn.boost.org/trac/boost/query?status=!closed&page=3&order=summary&row=description: #9331
# Just using double instead for now
post-patch:
	${REINPLACE_CMD} \
		-e 's|logl|log|g' \
		-e 's|long double|double|g' \
		${WRKSRC}/src/*.cpp \
		${WRKSRC}/src/*.h

.include <bsd.port.mk>
