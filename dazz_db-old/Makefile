
PORTNAME=	dazz_db
# Must use the same version of dazz_db, daligner, pypeflow, and falcon!
PORTVERSION=	2016.07.21
CATEGORIES=	wip biology databases
# MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jacobsonnenberg0@gmail.com
COMMENT=	Dresden assembler for long read DNA projects

LICENSE=	BSD3CLAUSE

USES=		gmake tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	511f7b5057e41ceaa58b11165b3c4d777726d03c

WRKSRC=		${WRKDIR}/DAZZ_DB-${GH_TAGNAME}

MAKEFILE=	GNUmakefile

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/Catrack \
		${WRKSRC}/DAM2fasta \
		${WRKSRC}/DB2fasta \
		${WRKSRC}/DBdump \
		${WRKSRC}/DBdust \
		${WRKSRC}/DBrm \
		${WRKSRC}/DBshow \
		${WRKSRC}/DBsplit \
		${WRKSRC}/DBstats \
		${WRKSRC}/fasta2DAM \
		${WRKSRC}/fasta2DB \
		${WRKSRC}/rangen \
		${WRKSRC}/simulator \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} \
		${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} \
		${WRKSRC}/libdazzdb.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.post.mk>
