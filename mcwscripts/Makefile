############################################################################
# New ports collection Makefile for:   mcwscripts
# Date created:        26 Jan 2007
# Whom:                Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#
#
############################################################################

PORTNAME=	mcwscripts
PORTVERSION=	1.0
CATEGORIES=	wip misc
MASTER_SITES=	http://www.neuro.mcw.edu/~bacon/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Miscellaneous scripts

RUN_DEPENDS=	TLv:../../science/TLv \
		dosu:../../sysutils/dosu \
		setfg:../../misc/setfg

PREFIX=		${LOCALBASE}/mri
NO_BUILD=	yes

do-install:
	${MKDIR}		${PREFIX}/scripts
	${INSTALL_SCRIPT}	${WRKSRC}/* ${PREFIX}/scripts

.include <bsd.port.mk>
