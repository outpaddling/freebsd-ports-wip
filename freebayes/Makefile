PORTNAME=		freebayes
DISTVERSIONPREFIX=	v
DISTVERSION=		1.3.9
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bayesian haplotype-based polymorphism discovery and genotyping
WWW=		https://github.com/ekg/freebayes

LICENSE=	MIT

BUILD_DEPENDS=	fastahack>0:biology/fastahack \
		multichoose>0:math/multichoose
LIB_DEPENDS=	libhts.so:biology/htslib \
		libwfa2.so:wip/wfa2-lib \
		libsw.so:biology/smithwaterman \

# Submodules use older versions than the ports, so we cannot safely unbundle
# No shared libs are built by the submodules so there will be no conflicts
# Yes, there are actually 2 versions of intervaltree required
USES=		cmake:indirect compiler:c++14-lang localbase meson perl5 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ekg
USE_PERL5=	build

LDFLAGS+=	-lexecinfo
PLIST_FILES=	bin/bamleftalign bin/freebayes

.include <bsd.port.mk>
