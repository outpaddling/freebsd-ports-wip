# $FreeBSD$

PORTNAME=	mtr
PORTVERSION=	0.85
PORTREVISION=	${GITVERSION}
PORTEPOCH=	5
CATEGORIES=	net
MASTER_SITES=	https://github.com/${GITHUB_USER}/${PORTNAME}/tarball/${GITVERSION}/ \
		${MASTER_SITE_LOCAL}
DISTNAME=	${PORTNAME}-${GITVERSION}

MAINTAINER=	e@mail
COMMENT=	Traceroute and ping in a single network diagnostic tool

LICENSE=	GPLv2

PATCH_DEPENDS=	${AUTOCONF_DEPENDS} ${AUTOMAKE_DEPENDS}

GITHUB_USER=	traviscross
GITVERSION=	cd19508
WRKSRC=		${WRKDIR}/${GITHUB_USER}-${PORTNAME}-${GITVERSION}
FETCH_ARGS=	-Fpr

OPTIONS_DEFINE=	IPV6 X11
OPTIONS_DEFAULT=X11
X11_DESC=	Build X11-enabled mtr

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf automake

MAN8=		mtr.8
PLIST_FILES=	sbin/mtr

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--enable-ipv6
CATEGORIES+=	ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=--with-gtk
PATCH_DEPENDS+=	${LOCALBASE}/lib/libgtk-x11-2.0.so:${PORTSDIR}/x11-toolkits/gtk20
USE_GNOME=	gtk20
USES=		pkgconfig
.else
CONFIGURE_ARGS+=--without-gtk
PKGNAMESUFFIX+=	-nox11
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
