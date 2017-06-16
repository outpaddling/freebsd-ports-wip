# Created by: Jacob Sonnenberg <jacobsonnenberg0@gmail.com>
# $FreeBSD$

PORTNAME=	dazz_db
# Must use the same version of dazz_db, daligner, pypeflow, and falcon!
PORTVERSION=	2015.10.28
CATEGORIES=	wip biology databases
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jacobsonnenberg0@gmail.com
COMMENT=	Dresden assembler for long read DNA projects

LICENSE=	BSD3CLAUSE

USES=		gmake tar:xz

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
		${WRKSRC}/DB2quiva \
		${WRKSRC}/DBdust \
		${WRKSRC}/DBrm \
		${WRKSRC}/DBshow \
		${WRKSRC}/DBsplit \
		${WRKSRC}/DBstats \
		${WRKSRC}/fasta2DAM \
		${WRKSRC}/fasta2DB \
		${WRKSRC}/quiva2DB \
		${WRKSRC}/simulator \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} \
		${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} \
		${WRKSRC}/libdazzdb.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.post.mk>
