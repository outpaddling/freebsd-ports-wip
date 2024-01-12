PORTNAME=	lensnns
PORTVERSION=	2.63
PORTREVISION=	1
CATEGORIES=	wip math science
MASTER_SITES=	http://tedlab.mit.edu/~dr/Lens/Dist/ \
		http://www.neuro.mcw.edu/Ports/distfiles/
DISTNAME=	lens

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Light Efficient Neural Network Simulator
WWW=		https://tedlab.mit.edu/~dr/Lens/

RUN_DEPENDS=	webbrowser:../../www/webbrowser

USE_GMAKE=	yes
USE_TCL=	83

MAN1=		lensnns.1

SUB_FILES=	pkg-message lensnns.1 lensnns.cshrc lensnns.profile
PKGMESSAGE=	${WRKDIR}/pkg-message
WEB_BROWSER?=	webbrowser
MAKE_ARGS+=	HOSTTYPE="FreeBSD" TCL_VER=${TCL_VER} USE_TCL=${USE_TCL}

post-extract:
	@${MKDIR} ${WRKDIR}/lens
	${MV} ${WRKDIR}/[A-Z]* ${WRKDIR}/lens
	${REINPLACE_CMD} 's|netscape|${WEB_BROWSER}|g' ${WRKSRC}/Src/lensrc.tcl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Bin/FreeBSD/alens-2.63 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/Bin/FreeBSD/lens-2.63 ${PREFIX}/bin
	${LN} -s ${PREFIX}/bin/alens-2.63 ${PREFIX}/bin/alensnns
	${LN} -s ${PREFIX}/bin/lens-2.63 ${PREFIX}/bin/lensnns
	${INSTALL_MAN} ${WRKDIR}/lensnns.1 ${PREFIX}/share/man/man1
	@${MKDIR} ${PREFIX}/share/${PORTNAME}/Src/Images
	@${MKDIR} ${PREFIX}/share/${PORTNAME}/Examples
	@${MKDIR} ${PREFIX}/share/${PORTNAME}/Commands
	${INSTALL_DATA} ${WRKSRC}/Src/*.tcl \
		${PREFIX}/share/${PORTNAME}/Src
	${INSTALL_DATA} ${WRKSRC}/Src/Images/* \
		${PREFIX}/share/${PORTNAME}/Src/Images
	${INSTALL_DATA} ${WRKSRC}/Examples/* \
		${PREFIX}/share/${PORTNAME}/Examples
	${INSTALL_DATA} ${WRKSRC}/Commands/* \
		${PREFIX}/share/${PORTNAME}/Commands
	@${MKDIR} ${PREFIX}/etc/mri
	${INSTALL_SCRIPT} ${WRKDIR}/lensnns.cshrc ${WRKDIR}/lensnns.profile \
		${PREFIX}/etc/mri

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
