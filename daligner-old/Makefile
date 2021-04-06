
# Note: pthreads performance on FreeBSD 10.1 is lacking compared to
# CentOS 6 on identical hardware.  Investigate tuning options.

PORTNAME=	daligner
# Must use the same version of dazz_db, daligner, pypeflow, and falcon!
PORTVERSION=	2016.07.21
CATEGORIES=	wip biology
# MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Find all significant local alignments between reads

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libdazzdb.a:wip/dazz_db

USES=		gmake tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	31239e24e5b9756dedaad05c8a5193eff5a568d5

WRKSRC=		${WRKDIR}/DALIGNER-${GH_TAGNAME}

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
		${WRKSRC}/HPC.daligner \
		${WRKSRC}/LA4Falcon \
		${WRKSRC}/LA4Ice \
		${WRKSRC}/LAcat \
		${WRKSRC}/LAcheck \
		${WRKSRC}/LAdump \
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
