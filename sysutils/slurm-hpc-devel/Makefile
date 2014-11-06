# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD: head/sysutils/slurm-hpc/Makefile 336471 2013-12-14 19:01:33Z wg $

PORTNAME=	slurm
PORTVERSION=	14.11.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.schedmd.com/download/archive/ \
		http://www.schedmd.com/download/latest/ \
		http://www.schedmd.com/download/development/
PKGNAMESUFFIX=	-hpc
DISTNAME=	slurm-${PORTVERSION}-0rc3

MAINTAINER=	jwbacon@tds.net
COMMENT=	Simple Linux Utility for Resource Management

LICENSE=	GPLv1

LIB_DEPENDS=	libsysinfo.so:${PORTSDIR}/devel/libsysinfo \
		libhwloc.so:${PORTSDIR}/devel/hwloc \
		libmunge.so:${PORTSDIR}/security/munge \
		librrd.so:${PORTSDIR}/databases/rrdtool
# Testing for hdf5.so is insufficient.  It will accept hdf5 1.6 and
# slurm requires hdf5 1.8.  h5copy is present only in 1.8.
BUILD_DEPENDS+=	${LOCALBASE}/bin/h5copy:${PORTSDIR}/science/hdf5
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USES=		perl5 gmake tar:bz2

OPTIONS_DEFINE=	DOCS MYSQL PGSQL GTK2
GTK2_DESC=	Build GUI config tools (sview)

USERS=		slurm
GROUPS=		${USERS}

USE_RC_SUBR=	slurmctld slurmd
SUB_FILES+=	slurm.conf

# This is a new and complex port.  Allow debugging.
STRIP_CMD=	# NONE
# ${WRKSRC}/slurm is for pty.h in configure
CFLAGS+=	-I${WRKSRC}/slurm -I${LOCALBASE}/include -g -O1
LDFLAGS+=	-L${LOCALBASE}/lib -lsysinfo -lkvm

post-install:
	${INSTALL_DATA} ${WRKDIR}/slurm.conf ${STAGEDIR}${PREFIX}/etc/slurm.conf.sample

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
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

.if ${PORT_OPTIONS:MPGSQL}
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

.if ${PORT_OPTIONS:MGTK2}
# Note: Configure could not find pcre when building with no ports
# preinstalled on 9.1-RELEASE.  Worked fine on second try.
USE_GNOME=	glib20 gtk20	# sview
PLIST_FILES+=	bin/sview
.endif

# Can't disable configure test, so make it fail
#	${CP} ${FILESDIR}/pty.h ${WRKSRC}/slurm
post-patch:
.if ! ${PORT_OPTIONS:MGTK2}
	${REINPLACE_CMD} \
		-e 's|min_gtk_version=2.7.1|min_gtk_version=200.7.1|g' \
		${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/env python|${PYTHON_CMD}|g' \
		${WRKSRC}/doc/html/shtml2html.py \
		${WRKSRC}/doc/man/man2html.py

.include <bsd.port.mk>
