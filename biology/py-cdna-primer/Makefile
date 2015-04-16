# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	cDNA_primer
PORTVERSION=	2015.04.15
CATEGORIES=	python
MASTER_SITES=	http://www.acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Analyzing transcriptome data generated using the PacBio(R)

USES=		python shebangfix
USE_PYTHON=	distutils autoplist
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

post-patch:
		${REINPLACE_CMD} -i'' -e \
			's|/home/UNIXHOME/etseng/.*/bin/|/usr/bin/env |g' \
			${WRKSRC}/build/scripts-2.7/*.py

.include <bsd.port.mk>
