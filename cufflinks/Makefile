# Do not upgrade until crash bugs are worked out in 2.2.1 or later

PORTNAME=	cufflinks
PORTVERSION=	2.1.1
CATEGORIES=	wip biology
# No releases in Github repo, so no USE_GITHUB
MASTER_SITES=	http://cole-trapnell-lab.github.io/cufflinks/assets/downloads/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Transcript assembly, differential expression and regulation for RNA-Seq

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

# FreeBSD 11 math.h errors
# Tried: compiler:c++11-lang
# USE_GCC is a workaround
USES=		python
GNU_CONFIGURE=	yes
USE_GCC=	yes

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
		-e 's|shared_ptr|boost::shared_ptr|g' \
		-e 's|boost::shared_ptr.hpp|shared_ptr.hpp|g' \
		-e 's|boost::boost::|boost::|g' \
		-e 's|^mutex|boost::mutex|g' \
		-e 's|logl|log|g' \
		-e 's|long double|double|g' \
		-e 's|Lf|lf|g' \
		-e 's|Lg|lg|g' \
		${WRKSRC}/src/*.cpp \
		${WRKSRC}/src/*.h
	${REINPLACE_CMD} \
		-e 's|int& is_up|bool\& is_up|g' \
		${WRKSRC}/src/rounding.h

.include <bsd.port.mk>
