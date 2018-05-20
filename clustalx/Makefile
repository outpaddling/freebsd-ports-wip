# $FreeBSD$

PORTNAME=	clustalx
PORTVERSION=	2.1
CATEGORIES=	wip
MASTER_SITES=	http://www.clustal.org/download/current/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Multiple alignment of nucleic acid and protein sequences

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		qmake
USE_QT4=	corelib gui qmake_build xml

PLIST_FILES=	bin/clustalx

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clustalx ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
