PORTNAME=		modules
DISTVERSIONPREFIX=	v
DISTVERSION=		4.1.3
CATEGORIES=		wip sysutils tcl

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic modification of a user environment
WWW=		https://modules.sourceforge.net/

LICENSE=	GPLv2

USES=		gmake tcl
USE_GITHUB=	yes
GH_ACCOUNT=	cea-hpc
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-x \
		--with-version-path=${PREFIX}/Modules/versions \
		--mandir=${MANPREFIX}/man \
		--with-tcl-ver=${TCL_VER:S/.//} \
		--with-tcl-inc=${TCL_INCLUDEDIR} \
		--with-tcl-lib=${LOCALBASE}/lib \
		--with-tclx-ver=${TCL_VER:S/.//} \
		--disable-compat-version

PLIST_SUB=	MODULES_VERSION=${PORTVERSION}

post-patch:
	${CP} ${FILESDIR}/version.inc.in ${WRKSRC}

post-install:
	${CP} -R ${STAGEDIR}${PREFIX}/Modules/${PORTVERSION}/init \
		${STAGEDIR}${PREFIX}/Modules/init

.include <bsd.port.mk>
