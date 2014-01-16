# New ports collection makefile for:    cluster-admin
# Date created:         2010-1-15
# Whom:                 Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	cluster-admin
PORTVERSION=	0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Tools for building and managing HPC clusters

RUN_DEPENDS=	auto-append-line:../../sysutils/auto-admin

USE_XZ=		yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${STAGEDIR}${PREFIX}/sbin
	${MV} ${STAGEDIR}${PREFIX}/sbin/topnode ${STAGEDIR}${PREFIX}/bin
	${MV} ${STAGEDIR}${PREFIX}/sbin/slurm-shell ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/Man && for f in *.mdoc; \
	do \
		${INSTALL_MAN} $${f} \
			${STAGEDIR}${PREFIX}/man/man1/$${f%.mdoc}.1; \
	done)
	${MKDIR} ${STAGEDIR}${DATADIR}/WWW
	${INSTALL_DATA} ${WRKSRC}/Share/* ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/WWW/* ${STAGEDIR}${DATADIR}/WWW

.include <bsd.port.mk>
