# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

# Note: pthreads performance on FreeBSD 10.1 is lacking compared to
# CentOS 6 on identical hardware.  Investigate tuning options.

PORTNAME=	daligner
# Must use the same version of dazz_db, daligner, pypeflow, and falcon!
PORTVERSION=	2015.10.28
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Find all significant local alignments between reads

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libdazzdb.a:/usr/wip/biology/dazz_db

USES=		gmake tar:xz

MAKEFILE=	GNUmakefile

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

post-patch:
	for f in ${WRKSRC}/py_utils/*.py; do \
		${PRINTF} "#!${PYTHON_CMD}\n\n" > $$f.temp; \
		${CAT} $$f >> $$f.temp; \
		${MV} -f $$f.temp $$f; \
	done

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/DB2Falcon \
		${WRKSRC}/HPCdaligner \
		${WRKSRC}/HPCmapper \
		${WRKSRC}/LA4Falcon \
		${WRKSRC}/LAcat \
		${WRKSRC}/LAcheck \
		${WRKSRC}/LAmerge \
		${WRKSRC}/LAshow \
		${WRKSRC}/LAsort \
		${WRKSRC}/LAsplit \
		${WRKSRC}/daligner \
		${WRKSRC}/daligner_p \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/py_utils/*.py \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} \
		${WRKSRC}/*.h \
		${STAGEDIR}${PREFIX}/include
	${AR} rs ${STAGEDIR}${PREFIX}/lib/libdaligner.a \
		${WRKSRC}/align.o

.include <bsd.port.post.mk>
