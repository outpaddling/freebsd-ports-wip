# $FreeBSD$

PORTNAME=	freebayes
PORTVERSION=	2018.03.23
CATEGORIES=	wip biology
MASTER_SITES=	https://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bayesian haplotype-based polymorphism discovery and genotyping

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/intervaltree/IntervalTree.h:wip/intervaltree \
		${LOCALBASE}/include/multichoose/multichoose.h:wip/multichoose
LIB_DEPENDS=	libbamtools.so:wip/bamtools \
		libvcflib.so:wip/vcflib \
		libtabix.so:wip/tabixpp \
		libsw.so:wip/smithwaterman \
		libhts.so:biology/htslib

USES=		compiler:openmp gmake tar:xz

CFLAGS+=	-I${LOCALBASE}/include/bamtools \
		-I${LOCALBASE}/include/intervaltree \
		-I${LOCALBASE}/include/vcflib \
		-I${LOCALBASE}/include/multichoose \
		-I${LOCALBASE}/include/smithwaterman

# MAKEFILE=	Makefile.external-libs

# INSTALL_TARGET=	install-strip

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/bamleftalign bin/freebayes

.include <bsd.port.mk>
