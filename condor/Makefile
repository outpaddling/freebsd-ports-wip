# Note: Make sure there are no older versions of HTCondor installed during
#       build.  The build system may pick up incompatible headers and libs.

PORTNAME=	condor
PORTVERSION=	8.6.13
CATEGORIES=	wip sysutils net
MASTER_SITES=	http://www.acadix.biz/Ports/distfiles/
DISTNAME=	condor_src-${PORTVERSION}-all-all

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	High-throughput computing on distributively owned resources
WWW=		https://research.cs.wisc.edu/condor/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE-2.0.txt

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libkrb5support.so:security/krb5 \
		libpcre.so:devel/pcre \
		libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		${PY_BOOST}

# Does not build with Python 3
USES=		cmake:noninja cpe perl5 pgsql python:2.7 shebangfix ssl
USE_LDCONFIG=	yes
CPE_VENDOR=	condor_project
SHEBANG_FILES=	src/condor_scripts/condor_qsub \
		src/condor_gridmanager/remote_gahp \
		src/condor_examples/condor_limits_wrapper.sh \
		src/condor_examples/condor_schedd.init \
		src/condor_starter.V6.1/condor_ssh_to_job_shell_setup \
		src/condor_job_router/condor_router_history \
		src/condor_scripts/condor_top.pl

WRKSRC=		${WRKDIR}/condor-${PORTVERSION}
WANT_PGSQL=	server
CXXFLAGS+=	-I${LOCALBASE}/include -fPIC
LDFLAGS+=	-Wl,-rpath=${_GCC_RUNTIME}:${LOCALBASE}/lib:/usr/lib:/lib -fPIC
# Does not build with Python 3
CMAKE_ARGS=	-DCMAKE_CXX_FLAGS:STRING=${CXXFLAGS} \
		-DCMAKE_EXE_LINKER_FLAGS:STRING=${LDFLAGS} \
		-DPYTHON_INCLUDE_DIR:PATH=${LOCALBASE}/include/${PYTHON_VERSION} \
		-DPYTHON_LIBRARY:FILEPATH=${LOCALBASE}/lib/lib${PYTHON_VERSION}.so

SUB_FILES=	condor-config condor_config.local pkg-message
PLIST_SUB=	CONDOR_UVER=${PORTVERSION:S/./_/g}

USERS=		condor
GROUPS=		${USERS}

USE_RC_SUBR=	condor

PORTEXAMPLES=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-everything::
	@( ${PRINTF} "\nWARNING: Condor needs approximately 3GB to build!"; \
	   ${PRINTF} "         Please make sure your build environment has that much before continuing.\n" )

post-patch:
	@${REINPLACE_CMD} \
		-e 's,\(set( C_SHARE_EXAMPLES	\)share/condor,\1${EXAMPLESDIR_REL},' \
		${WRKSRC}/build/cmake/CondorPackageConfig.cmake
	@${REINPLACE_CMD} \
		-e '/create_symlink/d' \
		${WRKSRC}/src/condor_scripts/CMakeLists.txt
	@${REINPLACE_CMD} \
		-e 's|/usr/local/condor|${PREFIX}|g' \
		-e 's|$$(LOCAL_DIR)/condor_config.local|$$(RELEASE_DIR)/etc/condor_config.local|g' \
		-e 's|/bin/mail|/usr/bin/mail|g' \
		-e 's|/usr/bin/java|${LOCALBASE}/bin/java|g' \
		-e 's|^CONDOR_HOST|##  CONDOR_HOST|' \
		-e 's|#CONDOR_IDS=x.x|CONDOR_IDS=466.466|' \
		${WRKSRC}/src/condor_examples/condor_config.annotated
	@${REINPLACE_CMD} \
		-e 's|boost_python |boost_python27 |g' \
		${WRKSRC}/src/python-bindings/CMakeLists.txt

pre-configure:
	@if which condor_submit > /dev/null; then \
		${ECHO_CMD} "condor build may fail while condor is installed."; \
		${ECHO_CMD} "Deinstall condor and run make again."; \
		false; \
	fi

post-install:
	${INSTALL_DATA} \
		${STAGEDIR}${ETCDIR}/examples/condor_config.annotated \
		${STAGEDIR}${PREFIX}/etc/condor_config.sample
	${INSTALL_DATA} ${WRKDIR}/condor_config.local \
		${STAGEDIR}${PREFIX}/etc/condor_config.local.sample
	${INSTALL_SCRIPT} ${WRKDIR}/condor-config ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
