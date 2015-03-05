# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	TransDecoder
PORTVERSION=	2.0.1
CATEGORIES=	biology
MASTER_SITES=	http://github.com/TransDecoder/TransDecoder/archive/
DISTNAME=	${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Identify candidate coding regions within transcript sequences

LICENSE=	BSD3CLAUSE

# TransDecoder.LongOrfs suggests doing Pfam or BlastP searches?
RUN_DEPENDS=	cd-hit>=4.6.1:/usr/wip/biology/cd-hit

NO_BUILD=	yes

USES=		perl5

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	${REINPLACE_CMD} -e 's|/bin/bash|/usr/local/bin/bash|g' \
		${WRKSRC}/sample_data/runMe.sh \
		${WRKSRC}/util/pfam_mpi.pbs
	${REINPLACE_CMD} \
		-e 's|$$FindBin::RealBin/PerlLib|${LOCALBASE}/lib/TransDecoder/PerlLib|g' \
		-e 's|$$FindBin::Bin/../PerlLib|${LOCALBASE}/lib/TransDecoder/PerlLib|g' \
		${WRKSRC}/TransDecoder* \
		${WRKSRC}/util/*.pl
	${REINPLACE_CMD} \
		-e 's|$$FindBin::RealBin/util|${LOCALBASE}/libexec/TransDecoder/util|g' \
		${WRKSRC}/TransDecoder* \
		${WRKSRC}/util/*.pl

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/TransDecoder/PerlLib
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/TransDecoder/util
	${INSTALL_SCRIPT} ${WRKSRC}/PerlLib/* \
		${STAGEDIR}${PREFIX}/lib/TransDecoder/PerlLib
	${INSTALL_SCRIPT} ${WRKSRC}/TransDecoder* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/util/*.pl \
		${STAGEDIR}${PREFIX}/libexec/TransDecoder/util

.include <bsd.port.mk>
