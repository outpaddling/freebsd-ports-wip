PORTNAME=		vcflib
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.15
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C++ library and CLI tools for parsing and manipulating VCF files
WWW=		https://github.com/vcflib/vcflib

LICENSE=	MIT

NOT_FOR_ARCHS=	armv6 armv7
NOT_FOR_ARCHS_REASON=	requires OpenMP which is not supported

BUILD_DEPENDS=	simde>0:devel/simde \
		pybind11>0:devel/pybind11 \
		${PYTHON_PKGNAMEPREFIX}pypandoc>=1.4:textproc/py-pypandoc@${PY_FLAVOR}
LIB_DEPENDS=	libhts.so:biology/htslib \
		libwfa2.so:biology/wfa2-lib

USES=		cmake:noninja gmake localbase:ldflags pkgconfig python shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	ekg
GH_TUPLE=	ekg:fastahack:bb33265:fastahack/contrib/fastahack \
		ekg:filevercmp:df20dcc:filevercmp/contrib/filevercmp \
		ekg:fsom:56695e1:fsom/contrib/fsom \
		ekg:intervaltree:aa59377:intervaltree/contrib/intervaltree \
		edawson:libVCFH:44b6580:libVCFH/contrib/libVCFH \
		ekg:multichoose:255192e:multichoose/contrib/multichoose \
		ekg:smithwaterman:2610e25:smithwaterman/contrib/smithwaterman \
		vcflib:tabixpp:0f55194:tabixpp/contrib/tabixpp
SHEBANG_FILES=	scripts/*

OPTIONS_DEFINE=		ZIG
OPTIONS_DEFAULT=
OPTIONS_SUB=		yes

ZIG_DESC=		Include Zig language support

ZIG_BUILD_DEPENDS=	zig>0:lang/zig

# FIXME:
# ld: error: undefined symbol: __zig_probe_stack
# >>> referenced by Dwarf.zig:2183 (/usr/local/lib/zig/std/debug/Dwarf.zig:2183)
# >>>               .zig-cache/o/2643a3b6947cf9c92e588b33a16c4d39/libzig_zcu.o:(debug.Dwarf.ElfModule.load) in archive /usr/ports/wip/vcflib/work/vcflib-1.0.15/src/zig/zig-out/lib/libzig.a
# https://ziggit.dev/t/undefined-reference-in-exported-function/13785
CMAKE_ARGS+=	-DWFA_GITMODULE=OFF -DWFALIB=${LOCALBASE}/lib/libwfa2.so.0 \
		-DTABIXPP_LOCAL=${WRKSRC}/contrib/tabixpp
ZIG_CMAKE_OFF=	-DZIG=OFF

# Clang and GCC disable sse2 by default on i386, but it's required for vcflib
CFLAGS_i386=	-msse2

# filevercmp is deprecated.  Remove conflict when the port is removed.
CONFLICTS_INSTALL=	filevercmp libdisorder # include/disorder.h include/filevercmp.h include/pdflib.hpp

.include <bsd.port.options.mk>

post-stage:
.if ${PORT_OPTIONS:MZIG}
	${RM} ${STAGEDIR}/usr/lib/libzig.a
.endif

.include <bsd.port.mk>
