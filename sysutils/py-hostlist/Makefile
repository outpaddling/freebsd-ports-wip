# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	hostlist
PORTVERSION=	1.14
CATEGORIES=	sysutils
MASTER_SITES=	http://www.nsc.liu.se/~kent/python-hostlist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Manage SLURM host lists

LICENSE=	GPLv2

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes

post-patch:
	${REINPLACE_CMD} -e 's|share/man|man|g' \
		${WRKSRC}/setup.py \
		${WRKSRC}/python-hostlist.spec

.include <bsd.port.mk>
