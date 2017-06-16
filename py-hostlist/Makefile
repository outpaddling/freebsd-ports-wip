# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	hostlist
PORTVERSION=	1.14
CATEGORIES=	wip sysutils
MASTER_SITES=	http://www.nsc.liu.se/~kent/python-hostlist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Manage SLURM host lists

LICENSE=	GPLv2

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes

post-patch:
	${REINPLACE_CMD} -e 's|share/man|man|g' \
		${WRKSRC}/setup.py \
		${WRKSRC}/python-hostlist.spec

.include <bsd.port.mk>
