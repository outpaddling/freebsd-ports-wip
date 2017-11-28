# Created by: Jason Bacon <jwb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gast
PORTVERSION=	2016.02.10
CATEGORIES=	wip biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Global Alignment for Sequence Taxonomy

LICENSE=	GPLv2

RUN_DEPENDS=	vsearch:wip/vsearch \
		mothur:wip/mothur

USES=		perl5 tar:xz
USE_PERL5=	run

NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e \
                's|#use lib "/class/stamps-software/bin"|use lib "${SITE_PERL}/gast"|' \
                ${WRKSRC}/gast

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gast ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.pm \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
