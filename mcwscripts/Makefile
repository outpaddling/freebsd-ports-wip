############################################################################
############################################################################

PORTNAME=	mcwscripts
PORTVERSION=	1.0
CATEGORIES=	wip misc
MASTER_SITES=	http://www.neuro.mcw.edu/~bacon/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Miscellaneous scripts

RUN_DEPENDS=	TLv:../../science/TLv \
		dosu:../../sysutils/dosu \
		setfg:../../misc/setfg

PREFIX=		${LOCALBASE}/mri
NO_BUILD=	yes

do-install:
	@${MKDIR}		${PREFIX}/scripts
	${INSTALL_SCRIPT}	${WRKSRC}/* ${PREFIX}/scripts

.include <bsd.port.mk>
