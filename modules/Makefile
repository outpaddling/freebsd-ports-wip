# $FreeBSD: head/sysutils/modules/Makefile 420510 2016-08-20 13:23:00Z pawel $

PORTNAME=	modules
PORTVERSION=	3.2.10
PORTREVISION=	2
CATEGORIES=	wip sysutils tcl
MASTER_SITES=	SF/${PORTNAME}/Modules/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic modification of a user environment

LICENSE=	GPLv2

USES=		tcl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-x \
		--with-version-path=${PREFIX}/Modules/versions \
		--mandir=${MANPREFIX}/man \
		--with-tcl-ver=${TCL_VER:S/.//} \
		--with-tcl-inc=${TCL_INCLUDEDIR} \
		--with-tcl-lib=${LOCALBASE}/lib \
		--with-tclx-ver=${TCL_VER:S/.//}

PLIST_SUB=	MODULES_VERSION=${PORTVERSION}

post-extract:
	${MV} ${WRKSRC}/doc/modulefile.4.in ${WRKSRC}/doc/modulefile.5.in

post-install:
	${CP} -R ${STAGEDIR}${PREFIX}/Modules/${PORTVERSION}/init \
		${STAGEDIR}${PREFIX}/Modules/init

.include <bsd.port.mk>
