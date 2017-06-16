# New ports collection makefile for:	torque
# Date created:			20 Jul 2006
# Whom:				trasz
#
# $FreeBSD: ports/sysutils/torque/Makefile,v 1.24 2010/12/04 07:33:41 ade Exp $
#

PORTNAME=	torque
PORTVERSION=	4.0
CATEGORIES=	wip sysutils parallel
MASTER_SITES=	http://www.adaptivecomputing.com/resources/downloads/torque/4.0-beta/
DISTNAME=	torque-4.0.0-snap.26656snapstamp

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Open source distributed computing resource manager based on PBS

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-syslog \
		--disable-spool
USE_GMAKE=	yes
USE_RC_SUBR=	pbs_server.sh pbs_sched.sh pbs_mom.sh
SUB_FILES=	pkg-message torque-config
USE_PERL5=	yes
USE_LDCONFIG=	yes

CONFLICTS=	qstat-[0-9]* zh-qterm-[0-9]* torque-2* torque-3*

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/torque-config ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/torque.setup ${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
