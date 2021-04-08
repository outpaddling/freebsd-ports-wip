PORTNAME=	hostlist
PORTVERSION=	1.14
CATEGORIES=	wip sysutils
MASTER_SITES=	http://www.nsc.liu.se/~kent/python-hostlist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Manage SLURM host lists

LICENSE=	GPLv2

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

post-patch:
	${REINPLACE_CMD} -e 's|share/man|man|g' \
		${WRKSRC}/setup.py \
		${WRKSRC}/python-hostlist.spec

.include <bsd.port.mk>
