# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$
# Test new versions with Trinity before upgrading

PORTNAME=	transdecoder
PORTVERSION=	2.0.1
CATEGORIES=	wip biology perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Identify candidate coding regions within transcript sequences

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	cd-hit>=4.6.1:biology/cd-hit \
		p5-URI>0:net/p5-URI

NO_BUILD=	yes
NO_ARCH=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	sample_data/runMe.sh util/pfam_mpi.pbs

USE_GITHUB=	yes
GH_PROJECT=	TransDecoder

WRKSRC=		${WRKDIR}/${GH_PROJECT}-${PORTVERSION}

PERL_MOD_DIR=	${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
PERL_UTIL_DIR=	${PREFIX}/libexec/${PORTNAME}

post-patch:
	${REINPLACE_CMD} \
		-e 's|$$FindBin::RealBin/PerlLib|${PERL_MOD_DIR}|g' \
		-e 's|$$FindBin::Bin/../PerlLib|${PERL_MOD_DIR}|g' \
		-e 's|$$FindBin::RealBin/util|${PERL_UTIL_DIR}|g' \
		${WRKSRC}/TransDecoder* ${WRKSRC}/util/*.pl

do-install:
	${MKDIR} ${STAGEDIR}${PERL_MOD_DIR} ${STAGEDIR}${PERL_UTIL_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/PerlLib/* ${STAGEDIR}${PERL_MOD_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/TransDecoder* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/util/*.pl ${STAGEDIR}${PERL_UTIL_DIR}

.include <bsd.port.mk>
