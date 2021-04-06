
PORTNAME=	tk
PORTVERSION=	8.3.5
PORTREVISION=	10
CATEGORIES=	wip x11-toolkits tk
MASTER_SITES=	SF/tcl/Tcl/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}-src

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Graphical toolkit for TCL

USE_TCL=	83
USE_TCL_BUILD=	83

PORTSCOUT=	limit:^8\.3\.

LATEST_LINK=	tk83
USE_XORG=	x11
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}/unix
GNU_CONFIGURE=	yes
TK_VER=		8.3
SHORT_TK_VER=	83
CONFIGURE_ARGS=	--enable-shared --with-tcl=${PREFIX}/lib/tcl${TK_VER} \
		--includedir=${LOCALBASE}/include/tk${TK_VER}
CONFIGURE_ENV=	PORTSDIR=${PORTSDIR} TK_LIB_FILE=libtk${SHORT_TK_VER}.so.1
MAKE_ENV=	SHORT_TK_VER=${SHORT_TK_VER}
PLIST_SUB=	TK_VER=${TK_VER} SHORT_TK_VER=${SHORT_TK_VER}
NOPRECIOUSMAKEVARS=	Too many _MLINKS for README.html
TCL83_PORT?=	lang/tcl83

OPTIONS=	TK83_MAN "Install tk 8.3 manpages" off

.include <bsd.port.pre.mk>

TKBASE?=	${PKGCATEGORY}/${LATEST_LINK}

post-patch:
	@${REINPLACE_CMD} -e 's|X11/Intrinsic.h|X11/Xlib.h|g' ${WRKSRC}/configure

post-configure:
	${REINPLACE_CMD} \
		-e 's|${WRKDIRPREFIX}${.CURDIR}|$${WRKDIRPREFIX}${TKBASE}|' \
		${WRKSRC}/tkConfig.sh

post-install:
	${INSTALL_DATA} ${FILESDIR}/pkgIndex.tcl ${PREFIX}/lib/tk${TK_VER}/
.if !defined(NO_INSTALL_MANPAGES) && defined(WITH_TK83_MAN)
	@cd ${WRKSRC} && ${MAKE} -f Makefile install-doc
.endif

test:
	cd ${WRKSRC}; make test

.include <bsd.port.post.mk>
