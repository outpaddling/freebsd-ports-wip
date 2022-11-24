PORTNAME=		goldencheetah
DISTVERSIONPREFIX=	v
DISTVERSION=		3.6
DISTVERSIONSUFFIX=	-RC3
CATEGORIES=		wip games

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Training software for cyclists
WWW=		https://goldencheetah.org/

LICENSE=	BSD3CLAUSE GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libical.so:devel/libical \
		libqwtplot3d-qt5.so:math/qwtplot3d

USES=		bison gmake qmake qt:5
USE_GL=		gl glu
USE_QT=		charts core gui linguist network opengl \
		qmake rcc script sql svg uic webkit xml
USE_GITHUB=	yes
GH_PROJECT=	GoldenCheetah

DESKTOP_ENTRIES=	"${PORTNAME}" \
			"${COMMENT}" \
			"${DATADIR}/gc.png" \
			"${PORTNAME}" \
			"Education;Sports;" \
			false

INFO=		GC3-FAQ GC3-Release GC31-Release

OPTIONS_DEFINE=	DOCS

post-extract:
	${CP} ${WRKSRC}/src/gcconfig.pri.in ${WRKSRC}/src/gcconfig.pri
	${CP} ${WRKSRC}/qwt/qwtconfig.pri.in ${WRKSRC}/qwt/qwtconfig.pri

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/images/gc.png \
		${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${PREFIX}/${INFO_PATH}
	${INSTALL_DATA} ${WRKSRC}/doc/user/*.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/user/*.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
