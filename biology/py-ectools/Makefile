# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	ectools
PORTVERSION=	0.1
CATEGORIES=	python
MASTER_SITES=	http://github.com/jgurtowski/ectools/archive/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	v${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Tools for error correction and working with long read data

LICENSE=	BSD3CLAUSE

USES=		python shebangfix
SHEBANG_FILES=	*.sh
SUB_FILES=	pkg-message

# DEPENDS: nucmer celera

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && for script in schtats *.py *.sh; do ${INSTALL_SCRIPT} $$script ${STAGEDIR}${PREFIX}/bin/ec-$$script; done)
	${MKDIR} ${STAGEDIR}${DATADIR}/test
	cd ${WRKSRC}/test && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/test

.include <bsd.port.mk>
