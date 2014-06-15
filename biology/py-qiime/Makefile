# New ports collection makefile for:	qiime
# Date created:		2013-08-22
# Whom:			Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	qiime
PORTVERSION=	1.8.0
CATEGORIES=	biology science
MASTER_SITES=	https://github.com/qiime/qiime/archive/
DISTNAME=	${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Quantitative Insights Into Microbial Ecology

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

# Add notification so that users running uclust will be made aware of
# license restrictions.

#       install_requires=['numpy >= 1.5.1, <= 1.7.1',
#                        'matplotlib >= 1.1.0, <= 1.3.1', 'cogent == 1.5.3',
#                        'pynast == 1.2.2', 'qcli', 'gdata',
#                        'biom-format == 1.3.1', 'emperor >= 0.9.3'],
# Need Sphinx for html docs

USES=			shebangfix
SHEBANG_FILES=	scripts/ec2Clean scripts/ec2Dispatch
# USE_GCC=		any
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	qiime

.include <bsd.port.mk>
