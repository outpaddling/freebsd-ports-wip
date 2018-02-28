# $FreeBSD$

PORTNAME=	torque
PORTVERSION=	3.0.6
CATEGORIES=	wip sysutils parallel
MASTER_SITES=	http://www.adaptivecomputing.com/index.php?wpfb_dl=190 \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Open source distributed computing resource manager based on PBS

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-syslog \
		--disable-spool
USE_GMAKE=	yes
USE_RC_SUBR=	pbs_server pbs_sched pbs_mom
SUB_FILES=	pkg-message torque-config
USE_PERL5=	yes
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	qstat-[0-9]* zh-qterm-[0-9]* torque-2* torque-4*

post-patch:
	${REINPLACE_CMD} -E 's|ps[ \t]+-ef|ps -ax|g' ${WRKSRC}/torque.setup

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/torque-config ${PREFIX}/bin
.if defined(NOPORTEXAMPLES)
	${RM} -rf ${EXAMPLESDIR}
.else
	${INSTALL_SCRIPT} ${WRKSRC}/torque.setup ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
