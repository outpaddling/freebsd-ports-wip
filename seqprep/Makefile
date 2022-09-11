PORTNAME=	seqprep
PORTVERSION=	1.1
CATEGORIES=	wip biology
MASTER_SITES=	https://github.com/jstjohn/SeqPrep/archive/
DISTNAME=	v${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Strip adaptors and/or merge paired reads with overlap into single reads
WWW=		https://github.com/jstjohn/SeqPrep

WRKSRC=		${WRKDIR}/SeqPrep-${PORTVERSION}

post-patch:
	${REINPLACE_CMD} \
		-e 's|CC=|CC?=|' \
		-e 's|CFLAGS=|CFLAGS?=|' \
		-e 's|$${CFLAGS}|-c $${CFLAGS}|' \
		-e 's|$$(CFLAGS)|-c $$(CFLAGS)|' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} \
		-e 's|inline||' ${WRKSRC}/*.c ${WRKSRC}/*.h
	${REINPLACE_CMD} \
		-e 's|../SeqPrep|SeqPrep|g' \
		-e 's|/bin/bash|/bin/sh|g' \
		${WRKSRC}/Test/RUNTEST.sh
	@${MKDIR} ${WRKSRC}/Test/out ${WRKSRC}/Test/info

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/SeqPrep ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
