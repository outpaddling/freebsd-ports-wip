PORTNAME=		freebayes
DISTVERSIONPREFIX=	v
DISTVERSION=		1.3.9
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bayesian haplotype-based polymorphism discovery and genotyping
WWW=		https://github.com/ekg/freebayes

LICENSE=	MIT

BUILD_DEPENDS=	fastahack>=1.0.0:biology/fastahack \
		multichoose>=1.0.3.3:wip/multichoose \
		simde>=0.8.2:devel/simde \
		vcflib>=1.0.12:biology/vcflib \
		intervaltree>=0.1.2:wip/intervaltree \
		smithwaterman>=g20160702:biology/smithwaterman \
		wfa2-lib>=2.3.5:wip/wfa2-lib \
		tabixpp>=1.1.2:wip/tabixpp
LIB_DEPENDS=	libhts.so:biology/htslib

USES=		compiler:c++14-lang localbase meson perl5 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ekg
USE_PERL5=	build

LDFLAGS+=	-lexecinfo
PLIST_FILES=	bin/bamleftalign bin/freebayes

.include <bsd.port.mk>
