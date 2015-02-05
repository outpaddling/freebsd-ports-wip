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

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		gmake
# USE_GCC=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/bin/bash|/usr/local/bin/bash|g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/transdecoder_plugins/Makefile \
		${WRKSRC}/sample_data/runMe.sh \
		${WRKSRC}/util/pfam_mpi.pbs

.include <bsd.port.mk>
