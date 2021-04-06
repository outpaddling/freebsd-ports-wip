
PORTNAME=	rnammer
PORTVERSION=	1.2
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	wip biology
MASTER_SITES=	http://www.cbs.dtu.dk/services/RNAmmer/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Predicts 5s/8s, 16s/18s, and 23s/28s ribosomal RNA

#LICENSE=

USES=		shebangfix tar:Z
SHEBANG_FILES=	*rnammer xml2*

RUN_DEPENDS=	p5-Getopt-Long>=2:devel/p5-Getopt-Long \
		p5-Data-Dumper>=2:devel/p5-Data-Dumper

NO_BUILD=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && tar zxvf ${DISTDIR}/${DISTFILES}

post-patch:
	${REINPLACE_CMD} \
		-e 's|/usr/cbs/bio/src/rnammer-1.2|${PREFIX}|g' \
		-e 's|$$INSTALL_PATH/lib|${DATADIR}|g' \
		-e 's|$$INSTALL_PATH/xml|${PREFIX}/bin/xml|g' \
		-e 's|$$INSTALL_PATH/core-rnammer|${PREFIX}/bin/core-rnammer|g' \
		-e "s|'\$$INSTALL_PATH'|'${PREFIX}'|g" \
		-e 's|/usr/cbs/bio/bin/linux64/hmmsearch|${PREFIX}/bin/hmmsearch|g' \
		-e 's|Linux|FreeBSD|g' \
		-e 's|/usr/bin/perl|${LOCALBASE}/bin/perl|g' \
		${WRKSRC}/rnammer

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/*rnammer ${WRKSRC}/xml2* \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} '*' ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/example && ${COPYTREE_SHARE} '*' ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
