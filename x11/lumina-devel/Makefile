# Created by: Ken Moore <ken@pcbsd.org>
# $FreeBSD: head/x11/lumina/Makefile 410144 2016-03-04 18:44:43Z kmoore $

PORTNAME=	lumina
PORTVERSION=	0.9.1
CATEGORIES=	x11
PKGNAMESUFFIX=	-devel

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Lumina Desktop Environment

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	xorg>=0:x11/xorg \
		fluxbox>=0:x11-wm/fluxbox \
		fluxbox-tenr-styles-pack>=0:x11-themes/fluxbox-tenr-styles-pack \
		kde4-icons-oxygen>=0:x11-themes/kde4-icons-oxygen \
		xscreensaver:x11/xscreensaver \
		xscreensaver-demo:x11/xscreensaver \
		xbrightness:x11/xbrightness \
		xcompmgr:x11-wm/xcompmgr \
		numlockx:x11/numlockx

OPTIONS_DEFINE=	MULTIMEDIA PCBSD
OPTIONS_DEFAULT=	MULTIMEDIA
MULTIMEDIA_DESC=	Install multimedia support backend (gstreamer)
PCBSD_DESC=	Use the PC-BSD system interface settings.

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMULTIMEDIA}
RUN_DEPENDS+=	gstreamer1-plugins-core>=0:multimedia/gstreamer1-plugins-core
.endif

MAKE_JOBS_UNSAFE=yes

USE_XORG=	x11 xdamage
USE_XCB=		x11extras wm
USE_LDCONFIG=	yes
USE_QT5=	core gui network svg linguist multimedia imageformats \
		buildtools x11extras concurrent
USES=		desktop-file-utils qmake
USE_GITHUB=	yes
GH_ACCOUNT=	pcbsd
#GH_TAGNAME=	1e9b663c06a451b215f6fe47e920ff130f4d963a
#GH_TAGNAME=	80cdfa8494fcec4fce3b593777788fc1a0fdcaf6
GH_TAGNAME=	6e048b540dbce694f772bc8f6f3261e93d5f0170

#Setup the qmake configuration options
.if ${PORT_OPTIONS:MPCBSD}
QMAKE_ARGS=	CONFIG+="configure NO_I18N PCBSD"
.else
QMAKE_ARGS=	CONFIG+="configure NO_I18N"
.endif

.include <bsd.port.mk>
