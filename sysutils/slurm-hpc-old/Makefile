# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	slurm
PORTVERSION=	2.6.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.schedmd.com/download/archive/ \
		http://www.schedmd.com/download/latest/ \
		http://www.schedmd.com/download/development/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Simple Linux Resource Manager

LICENSE=	GPLv1

LIB_DEPENDS=	sysinfo:${PORTSDIR}/devel/libsysinfo \
		munge:${PORTSDIR}/security/munge \
		rrd:${PORTSDIR}/databases/rrdtool
BUILD_DEPENDS+=	${LOCALBASE}/bin/h5copy:${PORTSDIR}/science/hdf5-18
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USES=		perl5 gmake

OPTIONS=	MYSQL	"Build with MYSQL accounting support" off \
		PGSQL	"Build with POSTGRESQL accounting support" off \
		GUI	"Build GUI config tools (requires GTK2)" off

.if WITH_MYSQL
USE_MYSQL=	yes	# Job accounting
PLIST_FILES+=	lib/slurm/accounting_storage_mysql.a \
		lib/slurm/accounting_storage_mysql.la \
		lib/slurm/accounting_storage_mysql.so \
		lib/slurm/jobcomp_mysql.a \
		lib/slurm/jobcomp_mysql.la \
		lib/slurm/jobcomp_mysql.so
.else
# Can't disable configure test, so make it fail
CONFIGURE_ARGS+=--with-mysql_config=/nomysql
.endif

.if WITH_PGSQL
USE_PGSQL=	yes	# Job accounting
PLIST_FILES+=	lib/slurm/accounting_storage_pgsql.a \
		lib/slurm/accounting_storage_pgsql.la \
		lib/slurm/accounting_storage_pgsql.so \
		lib/slurm/jobcomp_pgsql.a \
		lib/slurm/jobcomp_pgsql.la \
		lib/slurm/jobcomp_pgsql.so
.else
# Can't disable configure test, so make it fail
CONFIGURE_ARGS+=--with-pg_config=/nopostgres
.endif

.if WITH_GUI
# Note: Configure could not find pcre when building with no ports
# preinstalled on 9.1-RELEASE.  Worked fine on second try.
USE_GNOME=	glib20 gtk20	# sview
PLIST_FILES+=	bin/sview
.else
# Can't disable configure test, so make it fail
post-patch:
	${REINPLACE_CMD} -e 's|min_gtk_version=2.7.1|min_gtk_version=200.7.1|' \
		${WRKSRC}/configure
.endif

CFLAGS+=	-I${LOCALBASE}/include -g -O1
LDFLAGS+=	-L${LOCALBASE}/lib -lsysinfo -lkvm

SUB_FILES=	slurm.conf pkg-message

USERS=		slurm
GROUPS=		${USERS}

USE_RC_SUBR=	slurmctld slurmd

MAN1=	\
	sacct.1 \
	sacctmgr.1 \
	salloc.1 \
	sattach.1 \
	sbatch.1 \
	sbcast.1 \
	scancel.1 \
	scontrol.1 \
	sdiag.1 \
	sinfo.1 \
	slurm.1 \
	smap.1 \
	sprio.1 \
	squeue.1 \
	sreport.1 \
	srun.1 \
	srun_cr.1 \
	sshare.1 \
	sstat.1 \
	strigger.1 \
	sview.1 \
	sh5util.1

MAN3=	\
	slurm_allocate_resources.3 \
	slurm_allocate_resources_blocking.3 \
	slurm_allocation_lookup.3 \
	slurm_allocation_lookup_lite.3 \
	slurm_allocation_msg_thr_create.3 \
	slurm_allocation_msg_thr_destroy.3 \
	slurm_api_version.3 \
	slurm_checkpoint.3 \
	slurm_checkpoint_able.3 \
	slurm_checkpoint_complete.3 \
	slurm_checkpoint_create.3 \
	slurm_checkpoint_disable.3 \
	slurm_checkpoint_enable.3 \
	slurm_checkpoint_error.3 \
	slurm_checkpoint_failed.3 \
	slurm_checkpoint_restart.3 \
	slurm_checkpoint_task_complete.3 \
	slurm_checkpoint_tasks.3 \
	slurm_checkpoint_vacate.3 \
	slurm_clear_trigger.3 \
	slurm_complete_job.3 \
	slurm_confirm_allocation.3 \
	slurm_create_partition.3 \
	slurm_create_reservation.3 \
	slurm_delete_partition.3 \
	slurm_delete_reservation.3 \
	slurm_free_ctl_conf.3 \
	slurm_free_front_end_info_msg.3 \
	slurm_free_job_alloc_info_response_msg.3 \
	slurm_free_job_info_msg.3 \
	slurm_free_job_step_create_response_msg.3 \
	slurm_free_job_step_info_response_msg.3 \
	slurm_free_node_info.3 \
	slurm_free_node_info_msg.3 \
	slurm_free_partition_info.3 \
	slurm_free_partition_info_msg.3 \
	slurm_free_reservation_info_msg.3 \
	slurm_free_resource_allocation_response_msg.3 \
	slurm_free_slurmd_status.3 \
	slurm_free_submit_response_response_msg.3 \
	slurm_free_trigger_msg.3 \
	slurm_get_end_time.3 \
	slurm_get_errno.3 \
	slurm_get_job_steps.3 \
	slurm_get_rem_time.3 \
	slurm_get_select_jobinfo.3 \
	slurm_get_triggers.3 \
	slurm_hostlist_create.3 \
	slurm_hostlist_destroy.3 \
	slurm_hostlist_shift.3 \
	slurm_init_job_desc_msg.3 \
	slurm_init_part_desc_msg.3 \
	slurm_init_resv_desc_msg.3 \
	slurm_init_trigger_msg.3 \
	slurm_init_update_front_end_msg.3 \
	slurm_init_update_node_msg.3 \
	slurm_init_update_step_msg.3 \
	slurm_job_cpus_allocated_on_node.3 \
	slurm_job_cpus_allocated_on_node_id.3 \
	slurm_job_step_create.3 \
	slurm_job_step_launch_t_init.3 \
	slurm_job_step_layout_free.3 \
	slurm_job_step_layout_get.3 \
	slurm_job_will_run.3 \
	slurm_jobinfo_ctx_get.3 \
	slurm_kill_job.3 \
	slurm_kill_job_step.3 \
	slurm_load_ctl_conf.3 \
	slurm_load_front_end.3 \
	slurm_load_job.3 \
	slurm_load_job_user.3 \
	slurm_load_jobs.3 \
	slurm_load_node.3 \
	slurm_load_node_single.3 \
	slurm_load_partitions.3 \
	slurm_load_reservations.3 \
	slurm_load_slurmd_status.3 \
	slurm_notify_job.3 \
	slurm_perror.3 \
	slurm_pid2jobid.3 \
	slurm_ping.3 \
	slurm_print_ctl_conf.3 \
	slurm_print_front_end_info_msg.3 \
	slurm_print_front_end_table.3 \
	slurm_print_job_info.3 \
	slurm_print_job_info_msg.3 \
	slurm_print_job_step_info.3 \
	slurm_print_job_step_info_msg.3 \
	slurm_print_node_info_msg.3 \
	slurm_print_node_table.3 \
	slurm_print_partition_info.3 \
	slurm_print_partition_info_msg.3 \
	slurm_print_reservation_info.3 \
	slurm_print_reservation_info_msg.3 \
	slurm_print_slurmd_status.3 \
	slurm_read_hostfile.3 \
	slurm_reconfigure.3 \
	slurm_requeue.3 \
	slurm_resume.3 \
	slurm_set_debug_level.3 \
	slurm_set_trigger.3 \
	slurm_shutdown.3 \
	slurm_signal_job.3 \
	slurm_signal_job_step.3 \
	slurm_slurmd_status.3 \
	slurm_sprint_front_end_table.3 \
	slurm_sprint_job_info.3 \
	slurm_sprint_job_step_info.3 \
	slurm_sprint_node_table.3 \
	slurm_sprint_partition_info.3 \
	slurm_sprint_reservation_info.3 \
	slurm_step_ctx_create.3 \
	slurm_step_ctx_create_no_alloc.3 \
	slurm_step_ctx_daemon_per_node_hack.3 \
	slurm_step_ctx_destroy.3 \
	slurm_step_ctx_get.3 \
	slurm_step_ctx_params_t_init.3 \
	slurm_step_launch.3 \
	slurm_step_launch_abort.3 \
	slurm_step_launch_fwd_signal.3 \
	slurm_step_launch_wait_finish.3 \
	slurm_step_launch_wait_start.3 \
	slurm_strerror.3 \
	slurm_submit_batch_job.3 \
	slurm_suspend.3 \
	slurm_takeover.3 \
	slurm_terminate_job.3 \
	slurm_terminate_job_step.3 \
	slurm_update_front_end.3 \
	slurm_update_job.3 \
	slurm_update_node.3 \
	slurm_update_partition.3 \
	slurm_update_reservation.3 \
	slurm_update_step.3

MAN5=	\
	bluegene.conf.5 \
	cgroup.conf.5 \
	cray.conf.5 \
	gres.conf.5 \
	slurm.conf.5 \
	slurmdbd.conf.5 \
	topology.conf.5 \
	wiki.conf.5 \
	acct_gather.conf.5 \
	ext_sensors.conf.5

MAN8 =	\
	slurmctld.8 \
	slurmd.8 \
	slurmdbd.8 \
	slurmstepd.8 \
	spank.8

post-install:
.ifdef(NOPORTDOCS)
	${RM} -rf ${DOCSDIR}-${PORTVERSION}
.endif
.ifndef(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/slurm.conf ${EXAMPLESDIR}
.endif
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.mk>
