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

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync \
		auto-append-line:../../sysutils/auto-admin

MAN1=		cluster-setup.1 \
		cluster-adduser.1 \
		cluster-admin.1 \
		cluster-cp.1 \
		cluster-pkg_add.1 \
		cluster-port_add.1 \
		cluster-rmuser.1 \
		cluster-run.1 \
		cluster-shutdown.1 \
		cluster-update-ssh_config.1

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${PREFIX}/sbin
	(cd ${WRKSRC}/Man && for f in *.mdoc; \
	do \
		${INSTALL_MAN} $${f} \
			${PREFIX}/man/man1/$${f%.mdoc}.1; \
	done)
	${MKDIR} ${DATADIR}/WWW
	${INSTALL_DATA} ${WRKSRC}/Share/* ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/WWW/* ${DATADIR}/WWW

.include <bsd.port.mk>
