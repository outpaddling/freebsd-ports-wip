PORTNAME=	lumina-core
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.2-244
DISTVERSIONSUFFIX=	-g864fad6b
CATEGORIES=	wip x11

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lumina Desktop Environment
WWW=		https://lumina-desktop.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	kf6-extra-cmake-modules>=6.31.0:devel/kf6-extra-cmake-modules
RUN_DEPENDS=	fluxbox>=0:x11-wm/fluxbox \
		fluxbox-tenr-styles-pack>=0:x11-themes/fluxbox-tenr-styles-pack \
		xbrightness>=0:x11/xbrightness \
		compton>=0:x11-wm/compton \
		xrandr>=0:x11/xrandr \
		numlockx>=0:x11/numlockx \
		${LOCALBASE}/share/icons/La-Capitaine/index.theme:x11-themes/la-capitaine-icon-theme
LIB_DEPENDS+=	libxcb-ewmh.so:x11/xcb-util-wm \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util \
		libXcursor.so:x11/libXcursor \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++11-lang desktop-file-utils gettext gl qt:6 xorg
USE_GL=		gl
USE_XORG=	x11 xcb xdamage xext xfixes xi xrender
# 3d and location caused stage-qa warnings (might not need)
# USE_QT=		3d 5compat base declarative imageformats location multimedia svg tools:build translations
USE_QT=		5compat base declarative imageformats multimedia svg tools:build translations
# Old Qt5.  Verify above before removing.
# concurrent core dbus declarative gui \
# imageformats multimedia network svg widgets x11extras
USE_GITHUB=	yes
GH_ACCOUNT=	lumina-desktop
GH_PROJECT=	lumina

OPTIONS_DEFINE=		MULTIMEDIA
OPTIONS_DEFAULT=	MULTIMEDIA
OPTIONS_SUB=		yes

MULTIMEDIA_DESC=	Install multimedia support backend (gstreamer)
MULTIMEDIA_USES=	gstreamer
MULTIMEDIA_USE=		GSTREAMER=core

# FIXME: Can we build from src-qt6/core, like the Qt5 port?
WRKSRC_SUBDIR=	src-qt6

CONFIGURE_ENV+=	DESTDIR=${STAGEDIR}
WITH_DEBUG=	yes

CONFLICTS_INSTALL=	lumina-1.2.*

post-extract:
	@${RM} ${WRKSRC}/lumina-desktop*/extrafiles/screensavers/Warp*
	@${RM} ${WRKSRC}/lumina-desktop*/extrafiles/screensavers/*/Warp*

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/share -name "ecp.*" -delete

.include <bsd.port.mk>
