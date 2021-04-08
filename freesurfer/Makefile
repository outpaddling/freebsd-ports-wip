PORTNAME=	freesurfer
DISTVERSIONPREFIX=	release_
DISTVERSION=	6_0_0
CATEGORIES=	wip science

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Automatically segment white matter lesions on human brain MRI images

# Fake to silence warnings until custom license is defined
LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	liblapack.so:math/lapack

USES=		cmake fortran gmake libtool tar:bzip2
GNU_CONFIGURE=	yes
USE_GITHUB=	yes

# https://surfer.nmr.mgh.harvard.edu/fswiki/freesurfer_linux_developers_page
# sudo apt-get install build-essential \
#             tcsh \
#             libtool-bin \
#             libtool \
#             automake \
#            gfortran \
#            libglu1-mesa-dev \
#            libfreetype6-dev \
#            uuid-dev \
#            libxmu-dev \
#            libxmu-headers \
#            libxi-dev \
#            libx11-dev \
#            libxml2-utils \
#            libxt-dev \
#            libjpeg62-dev \
#            libxaw7-dev \
#            liblapack-dev

pre-configure:
	cd ${WRKSRC} && ./setup_configure

.include <bsd.port.mk>
