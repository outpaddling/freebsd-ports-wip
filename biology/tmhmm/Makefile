# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	tmhmm
PORTVERSION=	2.0
CATEGORIES=	biology
MASTER_SITES=	http://www.cbs.dtu.dk/cgi-bin/nph-sw_request?signalp/
DISTNAME=	${PORTNAME}-${PORTVERSION}c.Linux

MAINTAINER=	jwbacon@tds.net
COMMENT=	Predicts the presence and location of signal peptide cleavage sites

# LICENSE=

USES=		perl5 shebangfix
SHEBANG_FILES=	bin/tmhmmformat.pl

RESTRICTED=	Redistribution is not permitted

USE_GHOSTSCRIPT_RUN=	yes
RUN_DEPENDS=	gnuplot>=4:${PORTSDIR}/math/gnuplot \
		netpbm>=10:${PORTSDIR}/graphics/netpbm \
		p5-Getopt-Long>=2:${PORTSDIR}/devel/p5-Getopt-Long

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}c

NO_BUILD=	yes

.include <bsd.port.pre.mk>
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		is not redistributable. You must agree to the license terms at http://www.cbs.dtu.dk/cgi-bin/nph-sw_request?signalp and download ${DISTFILES} manually. Then copy ${DISTFILES} into ${DISTDIR} and run make again
.endif

post-patch:
	${REINPLACE_CMD} \
		-e 's|/usr/local/bin/gnuplot-3.7|gnuplot|g' \
		-e 's|/sbin/grep|grep|g' \
		-e 's|/usr/local/bin/gs|gs|g' \
		-e 's|/usr/freeware/bin/ppmtogif|ppmtogif|g' \
		${WRKSRC}/bin/tmhmmformat.pl

do-install:
	${CP} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} ${WRKSRC}/lib/* ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
