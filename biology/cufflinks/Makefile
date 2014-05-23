# Created by: Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
# $FreeBSD$

# http://cufflinks.cbcb.umd.edu/downloads/cufflinks-2.2.1.tar.gz
PORTNAME=	cufflinks
PORTVERSION=	2.2.1
CATEGORIES=	biology science
MASTER_SITES=	http://cufflinks.cbcb.umd.edu/downloads/

MAINTAINER=	bacon@sculpin.jbacon.dyndns.org
COMMENT=	Transcript assembly, differential expression, and differential regulation for RNA-Seq

# Just for speed: Recent GCC has better optimizer
# USE_GCC=	yes	# Fails to build with gcc 4.7
GNU_CONFIGURE=	yes
USE_PYTHON=	yes

BUILD_DEPENDS=	${LOCALBASE}/lib/libbam.a:../../biology/samtools \
		bjam:${PORTSDIR}/devel/boost-jam \
		eigen>0:${PORTSDIR}/math/eigen3
LIB_DEPENDS+=	libboost_iostreams.so:${PORTSDIR}/devel/boost-libs

CFLAGS+=	-I${LOCALBASE}/include/eigen3 \
		-Wno-unused -Wno-reorder -Wno-sign-compare

MAKE_JOBS_UNSAFE=yes

# FIXME: Find logl somewhere instead of falling back to log
# FIXME: boost problem and hackaround: https://svn.boost.org/trac/boost/query?status=!closed&page=3&order=summary&row=description: #9331
post-patch:
	${REINPLACE_CMD} \
		-e 's|logl|log|g' \
		-e 's|long double|double|g' \
		${WRKSRC}/src/*.cpp \
		${WRKSRC}/src/*.h


.include <bsd.port.mk>
