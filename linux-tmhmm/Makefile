PORTNAME=	tmhmm
PORTVERSION=	2.0
CATEGORIES=	wip biology
MASTER_SITES=	http://www.cbs.dtu.dk/cgi-bin/nph-sw_request?signalp/
DISTNAME=	${PORTNAME}-${PORTVERSION}c.Linux

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Predicts the presence and location of signal peptide cleavage sites

# LICENSE=

USE_LINUX=	yes
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	bin/tmhmmformat.pl bin/tmhmm

RESTRICTED=	Redistribution is not permitted

USE_GHOSTSCRIPT_RUN=	yes
RUN_DEPENDS=	gnuplot>=4:math/gnuplot \
		netpbm>=10:graphics/netpbm \
		p5-Getopt-Long>=2:devel/p5-Getopt-Long

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
	${REINPLACE_CMD} \
		-e 's|$$opt_basedir .=|$$opt_basedir = "${PREFIX}"; # |g' \
		-e 's|$$opt_libdir =|$$opt_libdir = "${DATADIR}"; # |g' \
		-e 's|$$opt_bindir =|$$opt_bindir = "${PREFIX}/bin"; # |g' \
		-e 's|$$opt_scrdir =|$$opt_scrdir = "${PREFIX}/bin"; # |g' \
		-e 's|decodeanhmm.$${unix}_$$arch|decodeanhmm|g' \
		${WRKSRC}/bin/tmhmm

do-install:
	${INSTALL_SCRIPT} \
		${WRKSRC}/bin/tmhmm ${WRKSRC}/bin/tmhmmformat.pl \
		 ${STAGEDIR}${PREFIX}/bin
	${CP} ${WRKSRC}/bin/decodeanhmm.Linux_i686 \
		${STAGEDIR}${PREFIX}/bin/decodeanhmm
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} ${WRKSRC}/lib/* ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
