PORTNAME=	mtr
PORTVERSION=	0.85
PORTREVISION=	${GITHUB_HASH}
PORTEPOCH=	8
CATEGORIES=	wip net
MASTER_SITES=	https://github.com/${GITHUB_USER}/${PORTNAME}/tarball/${GITHUB_HASH}/ \
		${MASTER_SITE_LOCAL}
DISTNAME=	${PORTNAME}-${GITHUB_HASH}

MAINTAINER=	e@mail
COMMENT=	Traceroute and ping in a single network diagnostic tool

LICENSE=	GPLv2

PATCH_DEPENDS=	${AUTOCONF_DEPENDS} ${AUTOMAKE_DEPENDS}

PKGNAMESUFFIX+=	-graph

GITHUB_USER=	yvs2014
GITHUB_HASH=	28f0506
WRKSRC=		${WRKDIR}/${GITHUB_USER}-${PORTNAME}-${GITHUB_HASH}
FETCH_ARGS=	-Fpr

OPTIONS_DEFINE=	IPV6 GTK ipinfo graphcairo_xcb graphcairo_xlib IDN Unicode sys_getopt
OPTIONS_DEFAULT=ipinfo Unicode
GTK_DESC=	Build X11/GTK enabled mtr
ipinfo_DESC=	ipinfo support
IDN_DESC=	IDN support
Unicode_DESC=	Unicode histogram support
sys_getopt_DESC=	System's own getopt
graphcairo_xcb_DESC=	graphcairo X11 XCB backend
graphcairo_xlib_DESC=	graphcairo X11 Xlib backend

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf automake

PLIST_FILES=	man/man8/mtr.8.gz \
		sbin/mtr

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CATEGORIES+=	wip ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if ${PORT_OPTIONS:MGTK}
PATCH_DEPENDS+=	${LOCALBASE}/lib/libgtk-x11-2.0.so:x11-toolkits/gtk20
USE_GNOME=	gtk20
USES=		pkgconfig
.else
CONFIGURE_ARGS+=--without-gtk
.endif

.if ${PORT_OPTIONS:Mipinfo}
CONFIGURE_ARGS+=--with-ipinfo
.endif

.if ${PORT_OPTIONS:Mgraphcairo_xcb}
LIB_DEPENDS+=	libcairo.so:graphics/cairo \
		libpango-1.0.so:x11-toolkits/pango \
		libxcb-keysyms.so:x11/xcb-util-keysyms
USE_XORG=	xcb
USES=		pkgconfig
CONFIGURE_ARGS+=--with-graphcairo-xcb
.else
.if ${PORT_OPTIONS:Mgraphcairo_xlib}
LIB_DEPENDS+=	libcairo.so:graphics/cairo \
		libpango-1.0.so:x11-toolkits/pango
USE_XORG=	x11
USES=		pkgconfig
CONFIGURE_ARGS+=--with-graphcairo-xlib
.endif
.endif

.if ${PORT_OPTIONS:MIDN}
LIB_DEPENDS+=	libidn.so:dns/libidn
CONFIGURE_ARGS+=--with-libidn
.endif

.if ${PORT_OPTIONS:MUnicode}
CONFIGURE_ARGS+=--with-unicode
.endif

.if ${PORT_OPTIONS:Msys_getopt}
CONFIGURE_ARGS+=--with-sys-getopt
.endif

pre-configure:
	@${AUTORECONF} -fi ${WRKSRC}

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "${PREFIX}/sbin/mtr is setuid \"root\" "
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please read about potential security issues"
	@${ECHO_MSG} "in file ${WRKSRC}/SECURITY (not installed)"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
