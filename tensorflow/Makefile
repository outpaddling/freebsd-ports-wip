# Created by: Jason Bacon <jwb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tensorflow
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=v
CATEGORIES=	wip math

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Open-source software library for Machine Intelligence

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		bazel:devel/bazel

USES=		python
USE_GITHUB=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	PYTHON_BIN_PATH=${PYTHON_CMD} \
		CC_OPT_FLAGS=" " \
		TF_NEED_JEMALLOC=0 \
		TF_NEED_GCP=0 \
		TF_NEED_HDFS=0 \
		TF_ENABLE_XLA=0 \
		USE_DEFAULT_PYTHON_LIB_PATH=1 \
		TF_NEED_OPENCL=0 \
		TF_NEED_CUDA=0

.include <bsd.port.mk>
