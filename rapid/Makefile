# $FreeBSD: head/math/rapid/Makefile 403506 2015-12-11 08:48:56Z miwi $

PORTNAME=	rapid
PORTVERSION=	2.01
CATEGORIES=	wip math science graphics
MASTER_SITES=	http://www.cs.sunysb.edu/~algorith/implement/RAPID/distrib/ \
		http://www.neuro.mcw.edu/Ports/distfiles/
DISTNAME=	RAPID_v2_01

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Robust and Accurate Polygon Interference Detection

LICENSE=	RAPID_LICENSE
LICENSE_NAME=	Software License for RAPID polygon interference detection
LICENSE_TEXT=	Commercial users must request a license
LICENSE_PERMS=	auto-accept

RESTRICTED=	For any commercial purpose, you must request a license from http://www.cs.unc.edu/~geom/OBB/OBBT.html

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

ALL_TARGET=
MAKE_JOBS_UNSAFE=	yes

MAKE_ENV+=	V=1

.include <bsd.port.pre.mk>

post-extract:
	${REINPLACE_CMD} -E "s/friend RAPID_Collide/friend int RAPID_Collide/" ${WRKSRC}/RAPID_private.H

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/RAPID
	${INSTALL_DATA}	${WRKSRC}/*.H ${STAGEDIR}${PREFIX}/include/RAPID
	${INSTALL_DATA}	${WRKSRC}/libRAPID.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${FILESDIR}/rapid.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
