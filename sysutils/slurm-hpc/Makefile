# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD: head/sysutils/slurm-hpc/Makefile 378061 2015-01-28 14:04:53Z skreuzer $

PORTNAME=	slurm
PORTVERSION=	14.11.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.schedmd.com/download/latest/ \
		http://www.schedmd.com/download/archive/ \
 		http://www.schedmd.com/download/development/
PKGNAMESUFFIX=	-hpc

MAINTAINER=	jwbacon@tds.net
COMMENT=	Simple Linux Utility for Resource Management

LICENSE=	GPLv2

LIB_DEPENDS=	libsysinfo.so:${PORTSDIR}/devel/libsysinfo \
		libhwloc.so:${PORTSDIR}/devel/hwloc \
		libmunge.so:${PORTSDIR}/security/munge \
		librrd.so:${PORTSDIR}/databases/rrdtool \
		libhdf5.so:${PORTSDIR}/science/hdf5

GNU_CONFIGURE=	yes

USE_LDCONFIG=	yes
USES=		gmake libtool perl5 python tar:bz2

OPTIONS_DEFINE=	DOCS MYSQL GTK2
OPTIONS_SUB=	yes

GTK2_USE=	GNOME=glib20,gtk20
MYSQL_USE=	MYSQL=yes

GTK2_DESC=	Build GUI config tool sview

USERS=		slurm
GROUPS=		${USERS}

USE_RC_SUBR=	slurmctld slurmd

# ${WRKSRC}/slurm is for pty.h in configure
CFLAGS+=	-I${WRKSRC}/slurm -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lsysinfo -lkvm

.include <bsd.port.options.mk>

# 1) SLURM'S configure has no option to disable the GTK test, so make it fail
#    if we don't want to build in GUI components.
#
# 2) SLURM's configure enables interactive jobs if pty.h exists.  Replacing
#    #include <pty.h> with appropriate headers will therefore not work, so
#    instead add a pty.h for the build.

post-patch:
.if ! ${PORT_OPTIONS:MGTK2}
	@${REINPLACE_CMD} \
		-e 's|min_gtk_version=2.7.1|min_gtk_version=200.7.1|g' \
		${WRKSRC}/configure
.endif
	@${CP} ${FILESDIR}/pty.h ${WRKSRC}/slurm
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/env python|${PYTHON_CMD}|g' \
		${WRKSRC}/doc/html/shtml2html.py \
		${WRKSRC}/doc/man/man2html.py
	@${REINPLACE_CMD} \
		-e 's|linux0|${HOST}|g' \
		-e 's|ClusterName=linux|ClusterName=${HOST}|g' \
		-e 's|jobacct_gather/linux|jobacct_gather/none|g' \
		-e 's|linux|compute-|g' \
		${WRKSRC}/etc/slurm.conf.example

post-stage:
.if ! ${PORT_OPTIONS:MDOCS}
	${RM} -rf ${STAGEDIR}${LOCALBASE}/share/doc/${PORTNAME}-${PORTVERSION}
.endif
	@${CP} ${WRKSRC}/etc/slurm.conf.example ${STAGEDIR}${PREFIX}/etc/

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
