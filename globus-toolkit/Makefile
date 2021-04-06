
PORTNAME=	globus_toolkit
DISTVERSION=	6.0.1535473965
CATEGORIES=	wip net java
MASTER_SITES=	https://downloads.globus.org/toolkit/gt6/stable/installers/src/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Open source software toolkit used for building grids

LICENSE=	APACHE20

# http://toolkit.globus.org/toolkit/docs/4.0/admin/docbook/ch03.html#s-prereq-required
# gtar? gsed? gmake? JDBC compliant database. For instance, PostgreSQL 7.1+
# gpt-3.2autotools2004 (shipped with the installers, but required if building standalone GPT bundles/packages)
# FIXME: Use base openssl.  Maybe create .pc file in FILESDIR and
# add to pkgconf path?
LIB_DEPENDS=	libltdl.so:devel/libltdl
BUILD_DEPENDS=	ant:devel/apache-ant \
		openssl>=1.0:security/openssl
RUN_DEPENDS=	openssl>=1.0:security/openssl

USES=		libtool perl5 pkgconfig shebangfix ssl
USE_JAVA=	yes
USE_GCC=	yes
USE_LDCONFIG=	${PREFIX}/globus-6/lib

# HAS_CONFIGURE allows overriding PREFIX
HAS_CONFIGURE=	yes
SHEBANG_FILES=	io/compat/test/globus-io-authorization-test.pl \
		io/compat/test/globus-io-tcp-test.pl \
		common/source/scripts/globus-makefile-header.in \
		common/source/scripts/globus-vararg-enums-doxygen-filter.pl \
		gsi_openssh/source/fixprogs \
		myproxy/source/myproxy-admin-adduser \
		myproxy/source/myproxy-replicate \
		myproxy/source/myproxy-test \
		myproxy/source/myproxy-test-replicate \
		myproxy/source/web/myproxy-get-delegation.cgi \
		myproxy/source/myproxy-passphrase-policy \
		myproxy/source/myproxy-server-setup \
		gass/copy/source/test/test-wrapper \
		gass/copy/source/test/guc-cc.pl \
		gass/copy/source/test/guc-stack.pl \
		gass/copy/source/test/guc-pp-cc.pl \
		gass/copy/source/test/guc-fw.pl \
		gass/cache_program/source/globus-gass-cache-util.pl.in \
		globus-vararg-enums-doxygen-filter.pl \
		gsi/proxy/proxy_utils/source/test/proxy-order-test.pl \
		gsi/proxy/proxy_utils/source/test/grid-proxy-utils-test.pl \
		gsi/proxy/proxy_ssl/source/test/TESTS-junit.pl \
		gsi/proxy/proxy_ssl/source/test/test_pci.pl \
		gsi/proxy/proxy_ssl/source/test/TESTS.pl \
		gsi/gssapi/source/test/compare-name-test-hybrid.pl \
		gsi/gssapi/source/test/compare-name-test-rfc2818.pl \
		gsi/gssapi/source/test/compare-name-test-gt2.pl \
		gsi/cert_utils/source/programs/globus-update-certificate-dir.in \
		gsi/simple_ca/source/test/grid-ca-create-test \
		gsi/simple_ca/source/test/grid-ca-sign-test \
		gsi/gss_assist/source/test/gss-assist-auth-test.pl \
		gsi/gss_assist/source/test/gss-assist-gridmap-test.pl \
		gsi/gss_assist/source/test/gridmap-test.pl \
		gsi/gss_assist/source/test/gridmap-tools-test.pl \
		gridftp/client/source/test/extended-transfer-test.pl \
		gridftp/client/source/test/extended-get-test.pl \
		gridftp/client/source/test/test-wrapper \
		gridftp/client/source/test/lingering-get-test.pl \
		gridftp/client/source/test/multiple-block-get-test.pl \
		gridftp/client/source/test/size-test.pl \
		gridftp/client/source/test/plugin-test.pl \
		gridftp/client/source/test/caching-extended-get-test.pl \
		gridftp/client/source/test/dir-test.pl \
		gridftp/client/source/test/run-tests.pl \
		gridftp/client/source/test/partial-put-test.pl \
		gridftp/client/source/test/caching-get-test.pl \
		gridftp/client/source/test/exist-test.pl \
		gridftp/client/source/test/get-test.pl \
		gridftp/client/source/test/partial-transfer-test.pl \
		gridftp/client/source/test/many-server.pl \
		gridftp/client/source/test/put-test.pl \
		gridftp/client/source/test/partial-get-test.pl \
		gridftp/client/source/test/run-backend-tests.pl \
		gridftp/client/source/test/user-auth-test.pl \
		gridftp/client/source/test/bad-buffer-test.pl \
		gridftp/client/source/test/create-destroy-test.pl \
		gridftp/client/source/test/caching-transfer-test.pl \
		gridftp/client/source/test/extended-put-test.pl \
		gridftp/client/source/test/transfer-test.pl \
		gridftp/net_manager/globus-vararg-enums-doxygen-filter.pl \
		gridftp/gridftp_driver/source/test/test-wrapper \
		gridftp/gridftp_driver/source/test/globus_gridftp_driver_test.pl \
		gridftp/gridftp_driver/source/globus-vararg-enums-doxygen-filter.pl \
		gram/jobmanager/scripts/globus-job-manager-script.pl.in \
		gram/jobmanager/auditing/source/globus-gram-audit.in \
		gram/jobmanager/scheduler_event_generator/source/test/make-test-data.pl \
		gram/jobmanager/scheduler_event_generator/source/test/TESTS.pl \
		gram/jobmanager/scheduler_event_generator/source/test/seg-api-test.pl \
		gram/jobmanager/source/test/jobmanager/user_test/globus-gram-job-manager-user-test.pl \
		gram/jobmanager/source/test/jobmanager/job-manager-script-test.pl.in \
		gram/jobmanager/source/test/jobmanager/submit_test/globus-gram-job-manager-submit-test.pl.in \
		gram/jobmanager/source/test/jobmanager/failure_test/globus-gram-job-manager-failure-test.pl.in \
		gram/jobmanager/source/test/jobmanager/stdio_test/globus-gram-job-manager-stdio-test.pl \
		gram/jobmanager/source/test/jobmanager/rsl_size_test/globus-gram-job-manager-rsl-size-test.pl.in \
		gram/jobmanager/source/test/jobmanager/job-manager-script-test.pl.in \
		gram/jobmanager/source/test/client/register-ping-test.pl \
		gram/jobmanager/source/test/client/failed-job-two-phase-commit.pl \
		gram/jobmanager/source/test/client/register-test.pl \
		gram/jobmanager/source/test/client/nonblocking-register-test.pl \
		gram/jobmanager/source/test/client/two-phase-commit-test.pl \
		xio/drivers/gsi/globus-vararg-enums-doxygen-filter.pl \
		xio/src/test/http-get-test.pl \
		xio/src/test/http-pingpong-test.pl \
		xio/src/test/http-header-test.pl \
		xio/src/test/http-throughput-test.pl \
		xio/src/test/http-post-test.pl \
		xio/src/test/timeout-test.pl \
		xio/src/test/http-put-test.pl \
		xio/src/globus-vararg-enums-doxygen-filter.pl

# FIXME: --build
CONFIGURE_ARGS+=--prefix=${PREFIX}/globus-6 --localstatedir=/var \
		--build=amd64-portbld-freebsd11.2 \
		--mandir=${PREFIX}/globus-6/man \
		--with-pkgconfigdir=${PREFIX}/globus-6/libdata/pkgconfig
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INSTALL_TARGET=	install-strip

post-configure:
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/gridftp/server/src/init/globus-gridftp-server \
		${WRKSRC}/gridftp/server/src/init/globus-gridftp-sshftp

# Remove suid
post-install:
	chmod 555 ${STAGEDIR}${PREFIX}/globus-6/libexec/ssh-keysign

.include <bsd.port.mk>
