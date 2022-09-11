PORTNAME=	pbfalcon
PORTVERSION=	2016.07.21
CATEGORIES=	wip biology
# MASTER_SITES=	http://acadix.biz/Ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Experimental PacBio diploid assembler
WWW=		https://github.com/PacificBiosciences/FALCON

LICENSE=	BSD3CLAUSE

# Must use the exact same version of dazz_db, daligner, pypeflow, and falcon!
# FIXME: Get to a newer version of rdflib and eliminate rdfextras
# FIXME: Check rdflib depend for 2016.07
RUN_DEPENDS=	dazz_db==${PORTVERSION}:wip/dazz_db \
		daligner==${PORTVERSION}:wip/daligner \
		${PYTHON_PKGNAMEPREFIX}pypeflow==${PORTVERSION}:wip/py-pypeflow \
		${PYTHON_PKGNAMEPREFIX}networkx>=0:math/py-networkx \
		${PYTHON_PKGNAMEPREFIX}rdflib==3.4.0:wip/py-rdflib340 \
		${PYTHON_PKGNAMEPREFIX}rdfextras==0.4:wip/py-rdfextras

USES=		python:3.6+ tar:xz
USE_PYTHON=	distutils

USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_PROJECT=	FALCON
GH_TAGNAME=	35d3d5b0706edf64577d35aed381988fb15623d9

WRKSRC=		${WRKDIR}/FALCON-${GH_TAGNAME}

post-patch:
	for f in ${WRKSRC}/src/py_scripts/*.py; do \
		printf "#!/usr/bin/env python\n\n" > $$f.temp; \
		cat $$f >> $$f.temp; \
		mv -f $$f.temp $$f; \
	done
	${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/falcon_kit/mains/run0.py \
		${WRKSRC}/falcon_kit/bash.py

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/python2.7/site-packages/*.so

.include <bsd.port.mk>
