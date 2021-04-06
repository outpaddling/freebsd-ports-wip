
PORTNAME=	bpcscripts
PORTVERSION=	2016.02.09
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Gast Illumina processing

LICENSE=	MIT

RUN_DEPENDS=	vsearch:wip/vsearch \
		fastaunique:wip/fastaunique

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	gast_ill

USE_GITHUB=	yes
GH_ACCOUNT=	MBL-Woods-Hole
GH_PROJECT=	BPC-scripts
GH_TAGNAME=	73c814a243955dc64ee248d9dacd4f71ac8640dc
# Old = fd89ad8b4297eae9bc2896ef65cb6151261f8e1e

NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} -e "s|use Taxonomy;|use lib(\"${SITE_PERL}/${PORTNAME}\"); &|g" \
		${WRKSRC}/gast_ill

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gast_ill ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.pm \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}

.include <bsd.port.mk>
