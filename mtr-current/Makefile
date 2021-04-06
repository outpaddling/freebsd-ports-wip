
PORTNAME=	mtr
PORTVERSION=	0.87.203
PORTREVISION=	${GITHUB_HASH}
#PORTEPOCH=	0
CATEGORIES=	wip net
MASTER_SITES=	https://github.com/${GITHUB_USER}/${PORTNAME}/tarball/${GITHUB_HASH}/ \
		${MASTER_SITE_LOCAL}
DISTNAME=	${PORTNAME}-${GITHUB_HASH}

MAINTAINER=	e@mail
COMMENT=	Traceroute and ping in a single network diagnostic tool

LICENSE=	GPLv2

PATCH_DEPENDS=	${AUTOCONF_DEPENDS} ${AUTOMAKE_DEPENDS}

GITHUB_USER=	traviscross
GITHUB_HASH=	0e5edbd
WRKSRC=		${WRKDIR}/${GITHUB_USER}-${PORTNAME}-${GITHUB_HASH}
FETCH_ARGS=	-Fpr

OPTIONS_DEFINE=	IPV6 X11
OPTIONS_DEFAULT=X11
X11_DESC=	Build X11-enabled mtr

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf automake

PLIST_FILES=	man/man8/mtr.8.gz \
		man/man8/mtr-packet.8.gz \
		sbin/mtr \
		sbin/mtr-packet

.include <bsd.port.options.mk>

USES=		pkgconfig

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--enable-ipv6
CATEGORIES+=	wip ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=--with-gtk
PATCH_DEPENDS+=	${LOCALBASE}/lib/libgtk-x11-2.0.so:x11-toolkits/gtk20
USE_GNOME=	gtk20
.else
CONFIGURE_ARGS+=--without-gtk
PKGNAMESUFFIX+=	-nox11
.endif

pre-configure:
	@${AUTORECONF} -fi ${WRKSRC}

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "${PREFIX}/sbin/mtr-packet is setuid \"root\" "
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please read about potential security issues"
	@${ECHO_MSG} "in file ${WRKSRC}/SECURITY (not installed)"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
