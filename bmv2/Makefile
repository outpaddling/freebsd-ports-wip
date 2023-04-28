PORTNAME=	bmv2
DISTVERSION=	1.15.0-28
DISTVERSIONSUFFIX=	-g2dd81c1
CATEGORIES=	wip net
PKGNAMEPREFIX=	p4lang-

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Reference P4 software switch
WWW=		https://example.com/bmv2

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# FIXME: devel/thrift conflicts with devel/thrift-cpp
# FIXME: lipcap dep is listed in case it's installed.  Force using base pcap?
BUILD_DEPENDS=	bash:shells/bash \
		thrift:wip/thrift
LIB_DEPENDS=	libnanomsg.so:net/nanomsg \
		libthrift.so:devel/thrift-cpp \
		libboost_system.so:devel/boost-libs \
		libgmp.so:math/gmp \
		libpcap.so:net/libpcap
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}thrift>=0:devel/py-thrift@${PY_FLAVOR}

USES=		autoreconf libtool localbase:ldflags python shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.py *.sh
SHEBANG_FILES+=	mininet/stress_test_ipv4.py.in \
		targets/psa_switch/psa_switch_CLI.in \
		targets/simple_switch/simple_switch_CLI.in \
		targets/simple_switch/tests/CLI_tests/run_one_test.py.in \
		tools/bm_CLI.in \
		tools/bm_nanomsg_events.in \
		tools/bm_p4dbg.in
GH_ACCOUNT=	p4lang
GH_PROJECT=	behavioral-model

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
