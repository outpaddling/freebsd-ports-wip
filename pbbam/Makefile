
PORTNAME=	pbbam
# DISTVERSION=	0.23.0 # Test with biology/unanimity before upgrading!
DISTVERSION=	1.0.6 # Test with biology/unanimity before upgrading!
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	PacBio BAM C++ library, with SWIG bindings

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libhts.so:biology/htslib \
		libboost_regex.so:devel/boost-libs \
		libpbcopper.so:wip/pbcopper

# Meson needs BOOST_ROOT=${LOCALBASE}
# https://github.com/mesonbuild/meson/issues/2239
USES=		compiler:c++14-lang localbase meson pkgconfig python
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences

pre-configure:
	@${REINPLACE_CMD} -e "s|'python'|'${PYTHON_VERSION}'|g" \
		${WRKSRC}/meson.build

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libpbbam.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libpbbam.so.1.0
	${RLN} ${STAGEDIR}${PREFIX}/lib/libpbbam.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libpbbam.so.1

.include <bsd.port.mk>
