PORTNAME=	signalp
PORTVERSION=	4.1
CATEGORIES=	wip biology
MASTER_SITES=	http://www.cbs.dtu.dk/cgi-bin/nph-sw_request?signalp/
DISTNAME=	${PORTNAME}-${PORTVERSION}c.Linux

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Predicts the presence and location of signal peptide cleavage sites
WWW=		https://www.cbs.dtu.dk/services/SignalP/

# LICENSE=

USE_LINUX=	yes
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	signalp

RESTRICTED=	Redistribution is not permitted

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_BUILD=	yes

.include <bsd.port.pre.mk>
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		is not redistributable. You must agree to the license terms at http://www.cbs.dtu.dk/cgi-bin/nph-sw_request?signalp and download ${DISTFILES} manually. Then copy ${DISTFILES} into ${DISTDIR} and run make again
.endif

post-patch:
	${REINPLACE_CMD} \
		-e 's|/usr/cbs/bio/src/signalp-4.1|${DATADIR}|g' \
		-e 's|$$ENV{SIGNALP}/bin/nnhowplayer.$$platform"."_"."$$architecture|${PREFIX}/bin/nnhowplayer|g' \
		-e 's|$$ENV{SIGNALP}/lib|${PREFIX}/${SITE_PERL_REL}/SignalP|g' \
		${WRKSRC}/signalp

do-install:
	${CP} ${WRKSRC}/bin/nnhowplayer.Linux_i686 \
		${STAGEDIR}${PREFIX}/bin/nnhowplayer
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/SignalP
	${CP} ${WRKSRC}/lib/* ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/SignalP
	${INSTALL_SCRIPT} ${WRKSRC}/signalp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/signalp.1 ${STAGEDIR}${PREFIX}/man/man1
	cd ${WRKSRC} && ${COPYTREE_SHARE} syn ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} test ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
