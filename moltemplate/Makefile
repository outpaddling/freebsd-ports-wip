PORTNAME=	moltemplate
PORTVERSION=	2013.7.15
CATEGORIES=	wip science
MASTER_SITES=	http://www.moltemplate.org/downloads/ \
		http://acadix.biz/Ports/distfiles/
DISTNAME=	${PORTNAME}_2013-7-15

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Text-based molecule builder for LAMMPS

RUN_DEPENDS=	bash:shells/bash

USE_PYTHON=	yes

SUB_FILES+=	pkg-message

NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/bin/bash|/usr/bin/env bash|g' \
		${WRKSRC}/src/moltemplate.sh

do-install:
	@${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/src/* ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/common ${DATADIR}
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.mk>
