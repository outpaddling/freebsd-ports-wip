PORTNAME=	cDNA_primer
PORTVERSION=	2015.08.17
CATEGORIES=	wip python
MASTER_SITES=	http://www.acadix.biz/Ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Analyzing transcriptome data generated using the PacBio(R)

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS+=	cython:lang/cython \
		${PYNUMPY} \
		${PYSCIPY} \
		${PYTHON_PKGNAMEPREFIX}pbh5tools>=0:wip/py-pbh5tools \
		${PYTHON_PKGNAMEPREFIX}networkx>=0:math/py-networkx
RUN_DEPENDS+=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pbh5tools>=0:wip/py-pbh5tools \
		${PYTHON_PKGNAMEPREFIX}networkx>=0:math/py-networkx \
		hmmer>=3.0:biology/hmmer \
		blasr>=${PORTVERSION}:wip/blasr \
		pbdagcon>=${PORTVERSION}:wip/pbdagcon

# Using bundled daligner and dazz_db for now
# https://github.com/PacificBiosciences/FALCON/issues/167#issuecomment-151914194
# PacBio response: Unfortunately, LA4Ice uses a very different version of
# daligner at the moment. We don't have a short-term solution for that.
# LA4Ice needs to use its own version.
#		daligner>=${PORTVERSION}:wip/daligner \

USES=		python:3.6+ shebangfix tar:xz
USE_PYTHON=	distutils
SHEBANG_FILES=	pbtools/pbtranscript/cleanup_ice.py \
		pbtools/pbtranscript/collapse_isoforms_by_sam.py \
		pbtools/pbtranscript/fusion_finder.py \
		pbtools/pbtranscript/ice_fa2fq.py \
		pbtools/pbtranscript/ice_partial.py \
		pbtools/pbtranscript/ice_pbdagcon.py \
		pbtools/pbtranscript/ice_quiver.py \
		pbtools/pbtranscript/pbtranscript.py \
		pbtools/pbtranscript/picking_up_ice.py \
		pbtools/pbtranscript/tofu_wrap.py \

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/pbtranscript-tofu/pbtranscript

# FIXME: Do we need the modified daligner described here?
# https://github.com/PacificBiosciences/cDNA_primer/wiki/Setting-up-virtualenv-and-installing-pbtranscript-tofu
pre-build:
		cd ${WRKSRC}/pbtools/pbtranscript/branch/C && \
			python setup2.py build_ext --inplace
		cd ${WRKSRC}/../external_daligner && unzip DALIGNER-d4aa4871122b35ac92e2cc13d9b1b1e9c5b5dc5c-ICEmod.zip && cd DALIGNER-d4aa4871122b35ac92e2cc13d9b1b1e9c5b5dc5c-ICEmod && ${REINPLACE_CMD} -e 's|gcc|${CC}|g' Makefile && ${GMAKE} clean && ${GMAKE}
		cd ${WRKSRC}/../external_daligner && unzip DAZZ_DB-40bb7e4b2041cdfd3c50b22201301b8df06342fa.zip && cd DAZZ_DB-40bb7e4b2041cdfd3c50b22201301b8df06342fa && ${REINPLACE_CMD} -e 's|gcc|${CC}|g' Makefile && ${GMAKE} clean && ${GMAKE}

post-stage:
		@${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin
		${MV} ${STAGEDIR}${PREFIX}/bin/pbtranscript.py \
			${STAGEDIR}${PREFIX}/${PORTNAME}/bin
		cd ${WRKSRC}/../external_daligner/DALIGNER-d4aa4871122b35ac92e2cc13d9b1b1e9c5b5dc5c-ICEmod && ${INSTALL_PROGRAM} HPCdaligner HPCmapper LA4Ice LAcat LAcheck LAmerge LAshow LAsort LAsplit daligner ${STAGEDIR}${PREFIX}/${PORTNAME}/bin
		cd ${WRKSRC}/../external_daligner/DAZZ_DB-40bb7e4b2041cdfd3c50b22201301b8df06342fa && ${INSTALL_PROGRAM} Catrack DAM2fasta DB2fasta DB2quiva DBdust DBrm DBshow DBsplit DBstats fasta2DAM fasta2DB quiva2DB simulator ${STAGEDIR}${PREFIX}/${PORTNAME}/bin
		${STRIP_CMD} \
			${STAGEDIR}${PYTHON_SITELIBDIR}/pbtools/pbtranscript/*.so \
			${STAGEDIR}${PYTHON_SITELIBDIR}/pbtools/pbtranscript/*/*.so
		${CHMOD} -R a+rX ${STAGEDIR}${PYTHON_SITELIBDIR}/pbtools/pbtranscript/data/

.include <bsd.port.mk>
