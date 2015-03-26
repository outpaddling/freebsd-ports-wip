# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	rnammer
PORTVERSION=	1.2
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	biology
MASTER_SITES=	http://www.cbs.dtu.dk/services/RNAmmer/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	jwbacon@tds.net
COMMENT=	Predicts 5s/8s, 16s/18s, and 23s/28s ribosomal RNA

#LICENSE=

USES=		shebangfix tar:Z
SHEBANG_FILES=	*rnammer xml2*

RUN_DEPENDS=	p5-Getopt-Long>=2:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-Data-Dumper>=2:${PORTSDIR}/devel/p5-Data-Dumper

NO_BUILD=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && tar zxvf ${DISTDIR}/${DISTFILES}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/*rnammer ${WRKSRC}/xml2* \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} '*' ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/example && ${COPYTREE_SHARE} '*' ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
