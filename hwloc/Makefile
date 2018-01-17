# $FreeBSD: head/wip devel/hwloc/Makefile 451721 2017-10-10 21:31:30Z linimon $
#
# WARNING: hwloc >= 1.11.3 has known issues when compiled with clang.
# It will work fine on some systems and crash on other identical systems.
# Do not upgrade this port before verifying that these issues are fixed.

PORTNAME=	hwloc
PORTVERSION=	1.11.2
PORTEPOCH=	1
CATEGORIES=	wip devel
MASTER_SITES=	http://www.open-mpi.org/software/hwloc/v${PORTVERSION:R}/downloads/ \
		http://icl.cs.utk.edu/open-mpi/software/hwloc/v${PORTVERSION:R}/downloads/

MAINTAINER=	phd_kimberlite@yahoo.co.jp
COMMENT=	Portable Hardware Locality software package

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=		amd64 armv6 armv7 i386
ONLY_FOR_ARCHS_REASON=	has not been ported to this architecture

LIB_DEPENDS=	libpciaccess.so:devel/libpciaccess

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static \
		--disable-opencl \
		--disable-cuda \
		--disable-nvml \
		--disable-gl
INSTALL_TARGET=	install-strip
USES=		iconv libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_GNOME=	libxml2

PORTDOCS=	*

OPTIONS_DEFINE=	CAIRO DOCS
OPTIONS_SUB=	yes

CAIRO_CONFIGURE_OFF=	--disable-cairo --without-x
CAIRO_CONFIGURE_ON=	--enable-cairo --with-x
CAIRO_LIB_DEPENDS=	libcairo.so:graphics/cairo
CAIRO_USE=		XORG=x11

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/doxygen-doc/html/* ${STAGEDIR}${DOCSDIR}/html/

.include <bsd.port.mk>
