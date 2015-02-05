# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	TransDecoder
PORTVERSION=	2.0.1
CATEGORIES=	biology
MASTER_SITES=	http://github.com/TransDecoder/TransDecoder/archive/
DISTNAME=	${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Identify candidate coding regions within transcript sequences

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

RUN_DEPENDS=	cd-hit:/usr/wip/biology/cd-hit
NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/bin/bash|/usr/local/bin/bash|g' \
		${WRKSRC}/sample_data/runMe.sh \
		${WRKSRC}/util/pfam_mpi.pbs

do-install:

.include <bsd.port.mk>
