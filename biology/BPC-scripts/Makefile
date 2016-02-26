# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	BPC-scripts
PORTVERSION=	fd89ad8b4297eae9bc2896ef65cb6151261f8e1e
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Global Alignment for Sequence Taxonomy

LICENSE=	GPLv2

# Run Depends:
# https://github.com/torognes/vsearch
# https://gist.github.com/meren/abd5c6f014da9aa554a4

USES=		perl5
USE_PERL5=	run

USE_GITHIB=	yes
GH_ACCOUNT=	MBL-Woods-Hole
GH_TAGNAME=	fd89ad8b4297eae9bc2896ef65cb6151261f8e1e

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gast ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.pm \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
