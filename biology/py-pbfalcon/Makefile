# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	pbfalcon
PORTVERSION=	2016.07.21
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Experimental PacBio diploid assembler

LICENSE=	BSD3CLAUSE

# Must use the exact same version of dazz_db, daligner, pypeflow, and falcon!
# Distfiles are rolled from a FALCON-integrate snapshot to ensure that
# this is possible.
# FIXME: Get to a newer version of rdflib and eliminate rdfextras
# FIXME: Check rdflib depend for 2016.07
RUN_DEPENDS=	dazz_db==${PORTVERSION}:/usr/wip/biology/dazz_db-2016.07.21 \
		daligner==${PORTVERSION}:/usr/wip/biology/daligner-2016.07.21 \
		${PYTHON_PKGNAMEPREFIX}pypeflow==${PORTVERSION}:/usr/wip/biology/py-pypeflow-2016.07.21 \
		${PYTHON_PKGNAMEPREFIX}networkx>=0:math/py-networkx \
		${PYTHON_PKGNAMEPREFIX}rdflib==3.4.0:/usr/wip/textproc/py-rdflib340 \
		${PYTHON_PKGNAMEPREFIX}rdfextras==0.4:/usr/wip/textproc/py-rdfextras

USES=		python tar:xz
USE_PYTHON=	distutils

# WRKSRC=		${WRKDIR}/FALCON-${DISTNAME}

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
