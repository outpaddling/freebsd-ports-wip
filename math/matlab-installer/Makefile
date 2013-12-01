# Created by:	Jason Bacon
# $FreeBSD$

PORTNAME=	matlab-installer
PORTVERSION=	0.2
CATEGORIES=	math science java
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Mathworks(r) Matlab installation tool

# Install Linux compilers for MEX.  Install all common shells except tcsh
# so that commands shelled-out from Matlab (e.g. mex) use Linux binaries 
# whenever possible.  Mex will not function with FreeBSD compilers.
# Tcsh PATH hash table will not include both /compat/linux/bin and /bin, etc.
# so it's better to use the FreeBSD tcsh and add /compat/linux bins to the
# path.
RUN_DEPENDS=	${LINUXBASE}/usr/bin/gfortran:../../devel/linux-f10-devtools \
		${LINUXBASE}/usr/share/terminfo:../../devel/linux-f10-ncurses-base \
		${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/graphics/linux-f10-dri \
		${LOCALBASE}/sbin/mount_image:../../sysutils/diskimage-tools \
		webbrowser:../../www/webbrowser

# Not needed if LD_LIBRARY_PATH is correct in shells started from Matlab
#		${LINUXBASE}/usr/bin/firefox:${PORTSDIR}/www/linux-firefox

USE_XZ=		yes
USE_LINUX=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	linux
JAVA_RUN=	yes

SUB_FILES=	pkg-message

NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} bin/matlab-browser

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/matlab-browser ${STAGEDIR}${PREFIX}/bin

post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.mk>
