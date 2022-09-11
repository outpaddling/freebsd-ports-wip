PORTNAME=	clustalx
DISTVERSION=	2.1
CATEGORIES=	wip biology
MASTER_SITES=	http://www.clustal.org/download/current/ \
		ftp://ftp.ebi.ac.uk/pub/software/clustalw2/${DISTVERSION}/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Multiple alignment of nucleic acid and protein sequences with GUI
WWW=		https://www.clustal.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		qmake qt:5
USE_QT=		qmake_build core gui widgets xml
USE_GL=		gl

PLIST_FILES=	bin/clustalx \
		${DATADIR}/colprot.xml \
		${DATADIR}/coldna.xml \
		${DATADIR}/colprint.xml \
		${DATADIR}/clustalx.hlp

pre-configure:
	@${REINPLACE_CMD} -e 's|col.*.xml|${DATADIR}/&|' \
		${WRKSRC}/ClustalQtParams.h
	@${REINPLACE_CMD} -e 's|clustalx.hlp|${DATADIR}/&|' \
		${WRKSRC}/HelpDisplayWidget.cpp
	@${REINPLACE_CMD} \
		-e 's|<QtGui>|<QtWidgets>|' \
		-e 's|toAscii|toLatin1|' \
		${WRKSRC}/*.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clustalx ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/col*.xml ${WRKSRC}/clustalx.hlp \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
