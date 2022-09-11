PORTNAME=		plink2
DISTVERSIONPREFIX=	v
# DISTVERSION=		g20190227
DISTVERSION=		2.00a2.3
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Whole genome association analysis toolset
WWW=		https://pngu.mgh.harvard.edu/~purcell/plink/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

# Seg faults with openblas
# #0  0x0000000800eb66ef in dgemm_otcopy_CORE2 ()
#   from /usr/local/lib/libopenblas.so.0
# Use openblas only for cblas functionality since it conflicts with math/cblas
LIB_DEPENDS=	libopenblas.so:math/openblas \
		liblapack.so:math/lapack \
		libblas.so:math/blas \
		libzstd.so:archivers/zstd

# We need Fortran LDFLAGS to link with Lapack.
USES=		fortran gmake python:3.6+ shebangfix
USE_GITHUB=	yes

SHEBANG_FILES=	Tests/*.sh Tests/*/*.sh \
		Tests/TEST_PHASED_VCF/*.py
GH_ACCOUNT=	chrchang
GH_PROJECT=	plink-ng
# GH_TAGNAME=	189224a

MAKEFILE=	${FILESDIR}/Makefile.generic
WRKSRC_SUBDIR=	2.0
CFLAGS+=	-DDYNAMIC_ZLIB
LDFLAGS+=	-lpthread
MAKE_ARGS=	ZLIB=-lz BLASFLAGS="-L${LOCALBASE}/lib -llapack -lblas -lopenblas -lgfortran"

INSTALL_TARGET=	install-strip

SUB_FILES=	plink2-test

post-patch:
	@${REINPLACE_CMD} -e 's|../../build_dynamic|${PREFIX}/bin|g' \
		${WRKSRC}/Tests/run_tests.sh
	@${REINPLACE_CMD} -e 's|^python3|${PYTHON_CMD}|g' \
		${WRKSRC}/Tests/TEST_PHASED_VCF/run_tests.sh
	@${CHMOD} a+rx \
		${WRKSRC}/Tests/run_tests.sh \
		${WRKSRC}/Tests/*/run_tests.sh

post-install:
	@(cd ${WRKSRC}/Tests && ${CHMOD} a+X run_tests.sh */run_tests.sh)
	(cd ${WRKSRC} && ${COPYTREE_BIN} Tests ${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${WRKDIR}/plink2-test ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/plink2-bench ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
