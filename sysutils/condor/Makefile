# Created by: Andy Pavlo
# $FreeBSD: ports/sysutils/condor/Makefile,v 1.15 2013/01/10 20:35:20 svnexp Exp $

PORTNAME=	condor
PORTVERSION=	8.0.3
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.acadix.biz/Ports/distfiles/
DISTNAME=	condor_src-${PORTVERSION}-all-all

MAINTAINER=	jwbacon@tds.net
COMMENT=	High-throughput computing on distributively owned resources

LIB_DEPENDS+=	krb5support:${PORTSDIR}/security/krb5 \
		pcre:${PORTSDIR}/devel/pcre \
		curl:${PORTSDIR}/ftp/curl

WRKSRC=		${WRKDIR}/condor-${PORTVERSION}
USE_GMAKE=	yes
USE_LDCONFIG=	yes
# USES=		cmake gmake perl5
# USE_GCC=	yes
USE_CMAKE=	yes
USE_PERL5=	yes
USE_PGSQL=	server
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-rpath=${LOCALBASE}/lib:/usr/lib:/lib
CMAKE_ARGS+=	-DCMAKE_CXX_FLAGS:STRING=${CXXFLAGS} \
		-DCMAKE_EXE_LINKER_FLAGS:STRING=${LDFLAGS}

SUB_FILES=	condor_config condor_config.local pkg-message

USERS=		condor
GROUPS=		${USERS}

USE_RC_SUBR=	condor

PORTEXAMPLES=	*
PORTDOCS=	*

MANCOMPRESSED=	yes

MAN1=	\
	bosco_cluster.1 \
	bosco_findplatform.1 \
	bosco_install.1 \
	bosco_ssh_start.1 \
	bosco_start.1 \
	bosco_stop.1 \
	bosco_uninstall.1 \
	condor_advertise.1 \
	condor_check_userlogs.1 \
	condor_checkpoint.1 \
	condor_chirp.1 \
	condor_cod.1 \
	condor_compile.1 \
	condor_config_val.1 \
	condor_configure.1 \
	condor_continue.1 \
	condor_dagman.1 \
	condor_drain.1 \
	condor_fetchlog.1 \
	condor_findhost.1 \
	condor_gather_info.1 \
	condor_glidein.1 \
	condor_history.1 \
	condor_hold.1 \
	condor_install.1 \
	condor_load_history.1 \
	condor_master.1 \
	condor_off.1 \
	condor_on.1 \
	condor_ping.1 \
	condor_power.1 \
	condor_preen.1 \
	condor_prio.1 \
	condor_procd.1 \
	condor_q.1 \
	condor_qedit.1 \
	condor_qsub.1 \
	condor_reconfig.1 \
	condor_release.1 \
	condor_reschedule.1 \
	condor_restart.1 \
	condor_rm.1 \
	condor_rmdir.1 \
	condor_router_history.1 \
	condor_router_q.1 \
	condor_router_rm.1 \
	condor_run.1 \
	condor_set_shutdown.1 \
	condor_ssh_to_job.1 \
	condor_stats.1 \
	condor_status.1 \
	condor_store_cred.1 \
	condor_submit.1 \
	condor_submit_dag.1 \
	condor_suspend.1 \
	condor_tail.1 \
	condor_transfer_data.1 \
	condor_updates_stats.1 \
	condor_userlog.1 \
	condor_userprio.1 \
	condor_vacate.1 \
	condor_vacate_job.1 \
	condor_version.1 \
	condor_wait.1 \
	condor_who.1 \
	gidd_alloc.1 \
	procd_ctl.1

.include <bsd.port.pre.mk>

pre-everything::
	@( ${PRINTF} "\nWARNING: Condor needs approximately 3GB to build!"; \
	   ${PRINTF} "         Please make sure your build environment has that much before continuing.\n" )

post-patch:
	@${REINPLACE_CMD} \
		-e 's,\(set( C_SHARE_EXAMPLES	\)share/condor,\1${EXAMPLESDIR_REL},' \
		${WRKSRC}/build/cmake/CondorPackageConfig.cmake
	@${REINPLACE_CMD} \
		-e '/create_symlink/d' ${WRKSRC}/src/condor_scripts/CMakeLists.txt

pre-install:
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	
post-install:
	${INSTALL_DATA} ${WRKDIR}/condor_config ${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/condor_config.local ${ETCDIR}
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if defined(NOPORTEXAMPLES)
	${RM} -rf ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
