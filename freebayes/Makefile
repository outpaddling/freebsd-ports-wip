PORTNAME=		freebayes
DISTVERSIONPREFIX=	v
DISTVERSION=		1.3.9
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bayesian haplotype-based polymorphism discovery and genotyping
WWW=		https://github.com/ekg/freebayes

LICENSE=	MIT

BUILD_DEPENDS=	fastahack>0:biology/fastahack \
		multichoose>0:math/multichoose \
		simde>0:devel/simde \
		vcflib>0:biology/vcflib \
		intervaltree>=0.1:wip/intervaltree \
		smithwaterman:biology/smithwaterman \
		wfa2-lib>0:wip/wfa2-lib \
		tabixpp>0:biology/tabixpp
LIB_DEPENDS=	libhts.so:biology/htslib \

USES=		compiler:c++14-lang localbase meson perl5 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ekg
USE_PERL5=	build

LDFLAGS+=	-lexecinfo
PLIST_FILES=	bin/bamleftalign bin/freebayes

.include <bsd.port.mk>
