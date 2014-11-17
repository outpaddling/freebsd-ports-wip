# Created by: Andy Pavlo
# $FreeBSD: head/sysutils/condor/Makefile 360673 2014-07-04 22:25:48Z adamw $

PORTNAME=	condor
PORTVERSION=	8.2.3
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.acadix.biz/Ports/distfiles/
DISTNAME=	condor_src-${PORTVERSION}-all-all

MAINTAINER=	jwbacon@tds.net
COMMENT=	High-throughput computing on distributively owned resources

LICENSE=	APACHE20

MAKE_JOBS_UNSAFE=	yes

LIB_DEPENDS+=	libkrb5support.so:${PORTSDIR}/security/krb5 \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libboost_python.so:${PORTSDIR}/devel/boost-python-libs

WRKSRC=		${WRKDIR}/condor-${PORTVERSION}
USE_LDCONFIG=	yes
USES+=		cmake gmake perl5 pgsql shebangfix
SHEBANG_FILES=	src/condor_scripts/condor_qsub \
		src/condor_gridmanager/remote_gahp \
		src/condor_examples/condor_limits_wrapper.sh \
		src/condor_examples/condor_schedd.init \
		src/condor_starter.V6.1/condor_ssh_to_job_shell_setup

WANT_PGSQL=	server
CXXFLAGS+=	-I${LOCALBASE}/include -fPIC
LDFLAGS+=	-rpath=${LOCALBASE}/lib:/usr/lib:/lib -fPIC
CMAKE_ARGS+=	-DCMAKE_CXX_FLAGS:STRING=${CXXFLAGS} \
		-DCMAKE_EXE_LINKER_FLAGS:STRING=${LDFLAGS}

SUB_FILES=	condor_config condor_config.local pkg-message

USERS=		condor
GROUPS=		${USERS}

USE_RC_SUBR=	condor

PORTEXAMPLES=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

# Builds with clang, but not gcc 4.2
.if ${OSVERSION} < 1000000 && !defined(WITH_OPENSSL_PORT)
USE_GCC=	yes
.endif

pre-everything::
	@( ${PRINTF} "\nWARNING: Condor needs approximately 3GB to build!"; \
	   ${PRINTF} "         Please make sure your build environment has that much before continuing.\n" )

post-patch:
	@${REINPLACE_CMD} \
		-e 's,\(set( C_SHARE_EXAMPLES	\)share/condor,\1${EXAMPLESDIR_REL},' \
		${WRKSRC}/build/cmake/CondorPackageConfig.cmake
	@${REINPLACE_CMD} \
		-e '/create_symlink/d' ${WRKSRC}/src/condor_scripts/CMakeLists.txt
post-install:
	${INSTALL_DATA} ${WRKDIR}/condor_config ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/condor_config.local ${STAGEDIR}${ETCDIR}
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
