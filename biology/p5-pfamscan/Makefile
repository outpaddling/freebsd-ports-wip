# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	p5-pfam
PORTVERSION=	2013.10.15
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
DISTNAME=	PfamScan-${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Pfam protein database scanner

USES=		perl5 tar:xz
# USE_PERL5=	?

# See README file for instructions on deps

# FIXME: Check version compat
BUILD_DEPENDS=	p5-bioperl>=1.6:${PORTSDIR}/biology/p5-bioperl \
		p5-Moose>=2:${PORTSDIR}/devel/p5-Moose

# Need 3.1?
RUN_DEPENDS+=	${BUILD_DEPENDS} \
		hmmer>=3.0:${PORTSDIR}/biology/hmmer

NO_BUILD=	yes

.include <bsd.port.mk>
