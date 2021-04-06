
PORTNAME=	pfamscan
PORTVERSION=	2013.10.15
CATEGORIES=	wip biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
#DISTNAME=	PfamScan-${PORTVERSION}
PKGNAMEPREFIX=	p5-
 
MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Pfam protein database scanner

USES=		perl5 tar:xz
USE_PERL5=	run

# See README file for instructions on deps

# FIXME: Check version compat
BUILD_DEPENDS=	p5-bioperl>=1.6:biology/p5-bioperl \
		p5-Moose>=2:devel/p5-Moose

# Need 3.1?
RUN_DEPENDS+=	${BUILD_DEPENDS} \
		hmmer>=3.0:biology/hmmer

NO_BUILD=	yes

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/bin
		${INSTALL_SCRIPT} ${WRKSRC}/pfam_scan.pl \
			${STAGEDIR}${PREFIX}/bin
		(cd ${WRKSRC} && ${COPYTREE_SHARE} Bio \
			${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/)

.include <bsd.port.mk>
