PORTNAME=	openmpi
PORTVERSION=	1.10.2
DISTVERSIONPREFIX=	1.10-
CATEGORIES=	wip net linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OpenMPI message passing interface

LICENSE=	BSD2CLAUSE

USES=		linux:c6
#USE_LINUX=	openssl
RPMVERSION=	2.el6
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes
#DESCR=		${.CURDIR}/pkg-descr

#PORTDOCS=	ANNOUNCEMENT CHANGES COPYRIGHT LICENSE README

# do not install any openldap configuration directories/files
#post-extract:
	#${RM} -rf ${WRKSRC}/etc

# use a native openldap configuration directories/files
#post-install:
	#@${MKDIR} ${STAGEDIR}${PREFIX}/etc
	#${LN} -sf ${LOCALBASE}/etc/openldap ${STAGEDIR}${PREFIX}/etc/openldap

.include <bsd.port.mk>
