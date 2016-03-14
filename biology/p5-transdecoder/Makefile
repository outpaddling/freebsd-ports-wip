# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	TransDecoder
PORTVERSION=	2.0.1
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Identify candidate coding regions within transcript sequences

LICENSE=	BSD3CLAUSE

# TransDecoder.LongOrfs suggests doing Pfam or BlastP searches?
RUN_DEPENDS=	cd-hit>=4.6.1:${PORTSDIR}/biology/cd-hit \
		p5-URI>0:${PORTSDIR}/net/p5-URI

NO_BUILD=	yes

USES=		perl5 shebangfix
SHEBANG_FILES=	sample_data/runMe.sh util/pfam_mpi.pbs

USE_GITHUB=	yes

post-patch:
	${REINPLACE_CMD} \
		-e 's|$$FindBin::RealBin/PerlLib|${LOCALBASE}/lib/TransDecoder/PerlLib|g' \
		-e 's|$$FindBin::Bin/../PerlLib|${LOCALBASE}/lib/TransDecoder/PerlLib|g' \
		-e 's|$$FindBin::RealBin/util|${LOCALBASE}/libexec/TransDecoder/util|g' \
		${WRKSRC}/TransDecoder* ${WRKSRC}/util/*.pl

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/TransDecoder/PerlLib
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/TransDecoder/util
	${INSTALL_SCRIPT} ${WRKSRC}/PerlLib/* \
		${STAGEDIR}${PREFIX}/lib/TransDecoder/PerlLib
	${INSTALL_SCRIPT} ${WRKSRC}/TransDecoder* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/util/*.pl \
		${STAGEDIR}${PREFIX}/libexec/TransDecoder/util

.include <bsd.port.mk>
