# $FreeBSD$

PORTNAME=	pypeflow
# Must use the same version of dazz_db, daligner, pypeflow, and falcon!
PORTVERSION=	2016.07.21
CATEGORIES=	wip biology
# MASTER_SITES=	http://acadix.biz/Ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jacobsonnenberg0@gmail.com
COMMENT=	Lightweight and reusable make/flow data process library

LICENSE=	MIT

USES=		python:3.6+ tar:xz
USE_PYTHON=	distutils

WRKSRC=		${WRKDIR}/pypeFLOW-${GH_TAGNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	4eeb8ffc79e0997a887b2879dadaae989e514827

post-build:
	${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/src/tests/test_pypeflow_task.py \
		${WRKSRC}/src/tests/test_pypeflow_data.py \
		${WRKSRC}/examples-pwatcher/ab/run.json \
		${WRKSRC}/presentation/pypeFLOW_tutorial.rst \
		${WRKSRC}/presentation/pypeFLOW_tutorial.html \
		${WRKSRC}/pwatcher/mains/pypeflow_example.py \
		${WRKSRC}/pwatcher/fs_based.py \
		${WRKSRC}/pypeflow/pwatcher_bridge.py \
		${WRKSRC}/pypeflow/task.py \
		${WRKSRC}/build/lib/pypeflow/pwatcher_bridge.py \
		${WRKSRC}/build/lib/pypeflow/task.py \
		${WRKSRC}/build/lib/pwatcher/fs_based.py \
		${WRKSRC}/build/lib/pwatcher/mains/pypeflow_example.py

.include <bsd.port.mk>
