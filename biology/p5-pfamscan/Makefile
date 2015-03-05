# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	p5-pfam
PORTVERSION=	2013.10.15
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
DISTNAME=	PfamScan-${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Pfam protein database scanner

USES=		tar:xz

# Need bioperl and Moose
# Need 3.1?
RUN_DEPENDS+=	hmmer>=3.0:${PORTSDIR}/biology/hmmer

NO_BUILD=	yes

.include <bsd.port.mk>
