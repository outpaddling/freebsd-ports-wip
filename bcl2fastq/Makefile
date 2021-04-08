PORTNAME=	bcl2fastq
DISTVERSION=	2.20.0
CATEGORIES=	wip
MASTER_SITES=	ftp://webdata2:webdata2@ussd-ftp.illumina.com/downloads/software/bcl2fastq/
DISTNAME=	bcl2fastq2-v2-20-0-tar

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Illumina Base Call (BCL) format to fastq converter

# Fake: Create proper license specs
LICENSE=	MIT
#LICENSE_FILE=

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

# boost, cmake, libxml2, libxslt, zlib
USES=		cmake compiler:openmp gnome zip
USE_GNOME=	libxml2 libxslt

CMAKE_ARGS=	-DHAVE_LIBXML2:BOOL=true -DHAVE_LIBXSLT:BOOL=true \
		-DBCL2FASTQ_VERSION=${PORTVERSION}
CXXFLAGS+=	--std=gnu++11 -D_GLIBCXX_USE_C99=1
WRKSRC=		${WRKDIR}/${PORTNAME}/src
# MAKE_JOBS_UNSAFE=	yes

post-extract:
	@(cd ${WRKDIR} && tar -zxf bcl2fastq2-v2.20.0.422-Source.tar.gz)

.include <bsd.port.mk>
