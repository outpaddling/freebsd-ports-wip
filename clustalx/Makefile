# $FreeBSD$

PORTNAME=	clustalx
PORTVERSION=	2.1
CATEGORIES=	wip
MASTER_SITES=	http://www.clustal.org/download/current/ \
		ftp://ftp.ebi.ac.uk/pub/software/clustalw2/2.1/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Multiple alignment of nucleic acid and protein sequences

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		qmake
USE_QT4=	corelib gui moc qmake_build xml

PLIST_FILES=	bin/clustalx \
		${DATADIR}/colprot.xml \
		${DATADIR}/coldna.xml \
		${DATADIR}/colprint.xml

post-patch:
	@${REINPLACE_CMD} -e 's|col.*.xml|${DATADIR}/&|' \
		${WRKSRC}/ClustalQtParams.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clustalx ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/col*.xml ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
