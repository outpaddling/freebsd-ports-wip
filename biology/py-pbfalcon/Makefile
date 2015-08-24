# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	pbfalcon
PORTVERSION=	2015.08.17
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Experimental PacBio diploid assembler

LICENSE=	BSD3CLAUSE

# Must use the exact same version of dazz_db, daligner, pypeflow, and falcon!
# Distfiles are rolled from a FALCON-integrate snapshot to ensure that
# this is possible.
# FIXME: Get to a newer version of rdflib and eliminate rdfextras
RUN_DEPENDS=	dazz_db==${PORTVERSION}:/usr/wip/biology/dazz_db \
		daligner==${PORTVERSION}:/usr/wip/biology/daligner \
		${PYTHON_PKGNAMEPREFIX}pypeflow==${PORTVERSION}:/usr/wip/biology/py-pypeflow \
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

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/python2.7/site-packages/falcon_kit/*.so

.include <bsd.port.mk>
