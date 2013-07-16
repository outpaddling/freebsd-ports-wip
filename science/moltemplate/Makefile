# New ports collection makefile for:	moltemplate
# Date created:		2013-07-16
# Whom:			Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	moltemplate
PORTVERSION=	2013.7.15
CATEGORIES=
MASTER_SITES=	http://www.moltemplate.org/downloads/
DISTNAME=	${PORTNAME}_2013-7-15

MAINTAINER=	jwbacon@tds.net
COMMENT=	Text-based molecule builder for LAMMPS

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

SUB_FILES+=	pkg-message

NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/bin/bash|/usr/bin/env bash|g' \
		${WRKSRC}/src/moltemplate.sh

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/src/* ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/common ${DATADIR}
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.mk>
