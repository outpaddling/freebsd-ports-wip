# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	BPC-scripts
PORTVERSION=	2016.02.09
CATEGORIES=	biology

MAINTAINER=	jwbacon@tds.net
COMMENT=	Gast Illumina processing

LICENSE=	MIT

RUN_DEPENDS=	vsearch:/usr/wip/biology/vsearch \
		fastaunique:/usr/wip/biology/fastunique

USES=		perl5
USE_PERL5=	run

USE_GITHUB=	yes
GH_ACCOUNT=	MBL-Woods-Hole
GH_TAGNAME=	73c814a243955dc64ee248d9dacd4f71ac8640dc

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gast_ill ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.pm \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}

.include <bsd.port.mk>
