# Created by: Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
# $FreeBSD$

# http://cufflinks.cbcb.umd.edu/downloads/cufflinks-2.2.1.tar.gz
PORTNAME=	cufflinks
PORTVERSION=	2.2.1
CATEGORIES=	biology science
MASTER_SITES=	http://cufflinks.cbcb.umd.edu/downloads/

MAINTAINER=	bacon@sculpin.jbacon.dyndns.org
COMMENT=	Transcript assembly, differential expression, and differential regulation for RNA-Seq

GNU_CONFIGURE=	yes
USE_PYTHON=	yes

BUILD_DEPENDS=	${LOCALBASE}/lib/libbam.a:../../biology/samtools \
		bjam:${PORTSDIR}/devel/boost-jam \
		eigen>0:${PORTSDIR}/math/eigen3
LIB_DEPENDS+=	libboost_iostreams.so:${PORTSDIR}/devel/boost-libs

CFLAGS+=	-I${LOCALBASE}/include/eigen3 -Wno-unused

MAKE_JOBS_UNSAFE=yes

# FIXME: Find logl somewhere instead of falling back to log
post-patch:
	${REINPLACE_CMD} -e 's|logl|log|g' ${WRKSRC}/src/differential.cpp

.include <bsd.port.mk>
