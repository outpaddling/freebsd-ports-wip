PORTNAME=	rtax
PORTVERSION=	0.984
CATEGORIES=	wip biology
MASTER_SITES=	http://static.davidsoergel.com/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Taxonomic classification of short paired-end reads from ribosomal RNA

LICENSE=	BSD3CLAUSE

USES=		perl5 shebangfix tar:tgz
SHEBANG_FILES=	rtax scripts/*.pl

NO_BUILD=	yes

PERL_MOD_DIR=	${PREFIX}/${SITE_PERL_REL}/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's|$$scripts/||g' ${WRKSRC}/rtax
	${REINPLACE_CMD} -e 's|$$FindBin::Bin|${PERL_MOD_DIR}|g' \
		${WRKSRC}/scripts/*.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rtax ${WRKSRC}/scripts/*.pl \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PERL_MOD_DIR}
	${INSTALL_DATA} ${WRKSRC}/scripts/*.pm \
		${STAGEDIR}${PERL_MOD_DIR}

.include <bsd.port.mk>
