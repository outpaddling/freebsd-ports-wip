# $FreeBSD$

PORTNAME=	mtr
PORTVERSION=	0.85
PORTREVISION=	${GITVERSION}
#PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/${GITHUB_USER}/${PORTNAME}/tarball/${GITVERSION}/ \
		${MASTER_SITE_LOCAL}
DISTNAME=	${PORTNAME}-${GITVERSION}

MAINTAINER=	e@mail
COMMENT=	Traceroute and ping in a single network diagnostic tool

LICENSE=	GPLv2

PATCH_DEPENDS=	${AUTOCONF_DEPENDS} ${AUTOMAKE_DEPENDS}

PKGNAMESUFFIX+=	-graph

GITHUB_USER=	yvs2014
GITVERSION=	bb9046a
WRKSRC=		${WRKDIR}/${GITHUB_USER}-${PORTNAME}-${GITVERSION}
FETCH_ARGS=	-Fpr

OPTIONS_DEFINE=	IPV6 GTK ipinfo graphcairo_xcb graphcairo_xlib IDN
OPTIONS_DEFAULT=graphcairo_xlib ipinfo
GTK_DESC=	Build X11/GTK enabled mtr
ipinfo_DESC=	ipinfo support
IDN_DESC=	IDN support
graphcairo_xcb_DESC=	graphcairo X11 XCB backend
graphcairo_xlib_DESC=	graphcairo X11 Xlib backend

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf automake

PLIST_FILES=	man/man8/mtr.8.gz \
		sbin/mtr

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CATEGORIES+=	ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if ${PORT_OPTIONS:MGTK}
PATCH_DEPENDS+=	${LOCALBASE}/lib/libgtk-x11-2.0.so:${PORTSDIR}/x11-toolkits/gtk20
USE_GNOME=	gtk20
USES=		pkgconfig
.else
CONFIGURE_ARGS+=--without-gtk
.endif

.if ${PORT_OPTIONS:Mipinfo}
CONFIGURE_ARGS+=--with-ipinfo
.endif

.if ${PORT_OPTIONS:Mgraphcairo_xcb}
LIB_DEPENDS+=	libcairo.so:${PORTSDIR}/graphics/cairo \
		libpango-1.0.so:${PORTSDIR}/x11-toolkits/pango \
		libxcb-keysyms.so:${PORTSDIR}/x11/xcb-util-keysyms
USE_XORG=	xcb
USES=		pkgconfig
CONFIGURE_ARGS+=--with-graphcairo-xcb
.else
.if ${PORT_OPTIONS:Mgraphcairo_xlib}
LIB_DEPENDS+=	libcairo.so:${PORTSDIR}/graphics/cairo \
		libpango-1.0.so:${PORTSDIR}/x11-toolkits/pango
USE_XORG=	x11
USES=		pkgconfig
CONFIGURE_ARGS+=--with-graphcairo-xlib
.endif
.endif

.if ${PORT_OPTIONS:MIDN}
LIB_DEPENDS+=	libidn.so:${PORTSDIR}/dns/libidn
CONFIGURE_ARGS+=--with-libidn
.endif

pre-configure:
	@${AUTORECONF} -fi ${WRKSRC}
	@${REINPLACE_CMD} -e 's|getopt.*$$(OBJEXT)||g; s|getopt.*[ch]||g; /getopt.*Po/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|"getopt\.h"|<getopt.h>|g' ${WRKSRC}/mtr.c

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "${PREFIX}/sbin/mtr is setuid \"root\" "
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please read about potential security issues"
	@${ECHO_MSG} "in file ${WRKSRC}/SECURITY (not installed)"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
