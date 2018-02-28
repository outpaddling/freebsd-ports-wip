# $FreeBSD: head/cad/scotch/Makefile 394778 2015-08-19 13:29:59Z mat $

PORTNAME=	scotch
DISTVERSION=	5.1.12b_esmumps
PORTREVISION=	5
CATEGORIES=	wip cad science
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/28978/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Package for graph and mesh partitioning and sparse matrix ordering

LICENSE=	CeCILL_C
LICENSE_NAME=	CeCILL-C
LICENSE_FILE=	${WRKSRC}/doc/CeCILL-C_V1-en.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CONFLICTS=	gbase-0.* gmap-2006.*

USES=		gmake

MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	DOCS EXAMPLES

.if defined(MAINTAINER_MODE)
USES+=		fortran
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:C/b_/_/}
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	scotch

CFLAGS+=	-I${LOCALBASE}/include

VER=		${PORTVERSION:R}
BINS=		acpl amk_ccc amk_fft2 amk_grf amk_hy amk_m2 amk_p2 atst	\
		gbase gcv gmap gmk_hy gmk_m2 gmk_m3 gmk_msh gmk_ub2	\
		gmtst gord gotst gout gpart gscat gtst mcv mmk_m2 mmk_m3\
		mord mtst
INCS=		esmumps.h scotch.h scotchf.h
LIBS=		libesmumps.a libscotch.a libscotcherr.a libscotcherrexit.a libscotchmetis.a
DOCVER=		${PORTVERSION:R:R:R}
PORTDOCS=	ptscotch_user${DOCVER}.pdf scotch_user${DOCVER}.pdf
EXAMPLES=	scotch_example_1.f scotch_example_2.f90

.if defined(WITH_OPENMPI)

MPIPREFIX=	mpi/openmpi/
PLIST_SUB+=	MPIPREFIX=${MPIPREFIX}
PKGNAMESUFFIX=	-openmpi
CC=		${LOCALBASE}/${MPIPREFIX}bin/mpicc
CFLAGS+=	-I${LOCALBASE}/${MPIPREFIX}include
LDLAGS+=	-L${LOCALBASE}/${MPIPREFIX}lib
DOCSDIR=	${PREFIX}/${MPIPREFIX}share/doc/scotch
EXAMPLESDIR=	${PREFIX}/${MPIPREFIX}share/examples/scotch

# Something unique to openmpi
LIB_DEPENDS+=	libopen-rte.so:net/openmpi

ALL_TARGET+=	ptscotch
MAKE_ENV+=	PATH=${PATH}:${LOCALBASE}/mpi/openmpi/bin

INCS+=		ptscotch.h ptscotchf.h
LIBS+=		libptesmumps.a libptscotch.a libptscotcherr.a libptscotcherrexit.a	\
		libptscotchparmetis.a
BINS+=		dggath dgmap dgord dgpart dgscat dgtst

PLIST_SUB+=	MPI=""

.elif defined(WITH_MPICH)

LIB_DEPENDS+=	libmpich.so:net/mpich2

ALL_TARGET+=	ptscotch
MAKE_ENV+=	PATH=${PATH}:${LOCALBASE}/mpich2/bin

INCS+=		ptscotch.h ptscotchf.h
LIBS+=		libptesmumps.a libptscotch.a libptscotcherr.a libptscotcherrexit.a	\
		libptscotchparmetis.a
BINS+=		dggath dgmap dgord dgpart dgscat dgtst

PLIST_SUB+=	MPI=""

.else	# No MPI

PLIST_SUB+=	MPI="@comment "

.endif

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
MF=	i686
.else
MF=	x86-64
.endif

pre-everything::
.if !(defined(WITH_MPICH) || defined(WITH_OPENMPI))
	@${ECHO_MSG}
	@${ECHO_MSG} "Define WITH_MPICH or WITH_OPENMPI if PT-Scotch is wanted."
	@${ECHO_MSG}
.endif

pre-configure:
	${REINPLACE_CMD} -e 's/-lthread/-pthread/;s/-lpthread/-pthread/'\
		-e 's/CLIBFLAGS	=/CLIBFLAGS	= -fPIC/'	\
		${WRKSRC}/src/Make.inc/Makefile.inc.${MF}_pc_freebsd
	${LN} -sf ${WRKSRC}/src/Make.inc/Makefile.inc.${MF}_pc_freebsd	\
		${WRKSRC}/src/Makefile.inc
	${REINPLACE_CMD} -E -e 's|cd (.*) ; * \$$\(MAKE\)|\$$(MAKE) -C \1|'	\
		-e 's|\&\& \$$\(MAKE\)||' ${WRKSRC}/src/Makefile

# FIXME: Update DOCSDIR and EXAMPLESDIR for mpi
do-install:
	${MKDIR} \
		${STAGEDIR}${PREFIX}/${MPIPREFIX}/bin \
		${STAGEDIR}${PREFIX}/${MPIPREFIX}/include \
		${STAGEDIR}${PREFIX}/${MPIPREFIX}/lib \
		${STAGEDIR}${MANPREFIX}/${MPIPREFIX}/man/man1
	${INSTALL_PROGRAM} ${BINS:S|^|${WRKSRC}/bin/|} ${STAGEDIR}${PREFIX}/${MPIPREFIX}/bin
	${INSTALL_DATA} ${INCS:S|^|${WRKSRC}/include/|} ${STAGEDIR}${PREFIX}/${MPIPREFIX}/include
	${INSTALL_DATA} ${LIBS:S|^|${WRKSRC}/lib/|} ${STAGEDIR}${PREFIX}/${MPIPREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${STAGEDIR}${MANPREFIX}/${MPIPREFIX}/man/man1
do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}
do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/grf ${STAGEDIR}${EXAMPLESDIR}/tgt
	${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/examples/|} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/grf/* ${STAGEDIR}${EXAMPLESDIR}/grf
	${INSTALL_DATA} ${WRKSRC}/tgt/* ${STAGEDIR}${EXAMPLESDIR}/tgt

.if defined(MAINTAINER_MODE)
regression-test:	install
	(amk_ccc 3 | acpl - ${WRKDIR}/ccc3.tgt &&	\
	${GUNZIP_CMD} -c ${EXAMPLESDIR}/grf/bump.grf.gz |	\
	gmap - ${WRKDIR}/ccc3.tgt ${WRKDIR}/brol.map)
	(cd ${WRKSRC}/examples &&	\
	${FC} -o scotch_test scotch_example_1.f ${FCFLAGS}	\
		-I${PREFIX}/${MPIPREFIX}/include ${LDFLAGS} -L${PREFIX}/${MPIPREFIX}/lib -lscotch -lscotcherr -lm	\
	&& ./scotch_test)
. if defined(WITH_MPICH) || defined(WITH_OPENMPI)
	(${GUNZIP_CMD} -c ${EXAMPLESDIR}/grf/bump.grf.gz | dgtst)
. endif
.endif

.include <bsd.port.mk>
