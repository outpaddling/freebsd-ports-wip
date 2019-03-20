# $FreeBSD: head/biology/clustalx/Makefile 486467 2018-12-02 15:41:47Z rene $

PORTNAME=	clustalx
DISTVERSION=	2.1
CATEGORIES=	wip biology
MASTER_SITES=	http://www.clustal.org/download/current/ \
		ftp://ftp.ebi.ac.uk/pub/software/clustalw2/${DISTVERSION}/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Multiple alignment of nucleic acid and protein sequences with GUI

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		qmake qt
USE_QT=		corelib gui moc qmake_build xml

PLIST_FILES=	bin/clustalx \
		${DATADIR}/colprot.xml \
		${DATADIR}/coldna.xml \
		${DATADIR}/colprint.xml \
		${DATADIR}/clustalx.hlp

post-patch:
	@${REINPLACE_CMD} -e 's|col.*.xml|${DATADIR}/&|' \
		${WRKSRC}/ClustalQtParams.h
	@${REINPLACE_CMD} -e 's|clustalx.hlp|${DATADIR}/&|' \
		${WRKSRC}/HelpDisplayWidget.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clustalx ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/col*.xml ${WRKSRC}/clustalx.hlp \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
