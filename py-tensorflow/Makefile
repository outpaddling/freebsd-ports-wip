# $FreeBSD$

PORTNAME=	tensorflow
PORTVERSION=	1.14.0
PORTREVISION=	1
DISTFILES=	v${PORTVERSION}.tar.gz:tensor
MASTER_SITES=	https://github.com/tensorflow/tensorflow/archive/:tensor
CATEGORIES=	wip science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAINTAINER=	ports@FreeBSD.org
COMMENT=	Computation using data flow graphs for scalable machine learning

.include "MASTER_SITES"

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.11.2:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.7.1:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.11.2:math/py-numpy@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}markdown>=2.6.8:textproc/py-markdown@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}bleach>=1.4.2:www/py-bleach@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}html5lib>=0.9999999:www/py-html5lib@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}protobuf>=3.2.0:devel/py-protobuf@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}wheel>=0.29.0:devel/py-wheel@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}mock>=1.3.0:devel/py-mock@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}werkzeug>=0.11.10:www/py-werkzeug@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}keras>=2.2.4:math/py-keras@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}absl>=0.7.1:devel/py-absl@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}gast>=0.2.2:devel/py-gast@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}astor>=0.5:devel/py-astor@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}termcolor>=1.1.0:devel/py-termcolor@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}wrapt>=1.11.2:devel/py-wrapt@${PY_FLAVOR} \
		bash:shells/bash \
		protobuf>=3.7.1:devel/protobuf \
		cython:lang/cython \
		swig3.0:devel/swig30 



RUN_DEPENDS=	${BUILD_DEPENDS}

LIB_DEPENDS=	libdouble-conversion.so:devel/double-conversion \
		libgpr.so:devel/grpc \
		libnsync.so:devel/nsync \
		libgoogle_cloud_cpp_common.so:devel/google-cloud-cpp \
		libflatbuffers.so:devel/flatbuffers \
		libsqlite3.so:databases/sqlite3 \
		libsnappy.so:archivers/snappy \
		liblmdb.so:databases/lmdb \
		libicuio.so:devel/icu \
		libjsoncpp.so:devel/jsoncpp \
		libpcre.so:devel/pcre \
		libre2.so:devel/re2 \
		libgif.so:graphics/giflib \
		libjpeg.so:graphics/jpeg \
		libpng.so:graphics/png \
		libcurl.so:ftp/curl
		


USES=		python:3.6 shebangfix

EXTRACT_ONLY=v${PORTVERSION}.tar.gz

DIST_SUBDIR=${PORTNAME}

USE_PYTHON=	autoplist distutils

BAZEL_BOOT=     --output_user_root=${WRKDIR}/bazel_out

SHEBANG_GLOB=	*.py

PLIST_SUB=	TF_PORT_VERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSREL:R} <= 10
BUILD_DEPENDS+=	bazel:devel/bazel-clang38
.else
BUILD_DEPENDS+=	bazel:devel/bazel
.endif

#clang has this check enabled by default, disable it
#see: https://github.com/tensorflow/tensorflow/issues/8894
.if ${ARCH} == "i386"
BAZEL_COPT+=--copt=-Wno-c++11-narrowing
.endif

post-patch:
	# Set up a local repository with our pre-downloaded packages
	# This prevents bazel downloading the files without modifying
	# the bzl files.
	@${MKDIR} ${WRKDIR}/bazel-cache
	@${MKDIR} ${WRKDIR}/bazel-distdir

.for file in ${DISTFILES:C/\:(.*)//}
	@${ECHO} "Moving ${file} to ${WRKDIR}/bazel-cache"
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${file} ${WRKDIR}/bazel-distdir
.endfor

	(cd ${WRKSRC} && \
	${REINPLACE_CMD} "s#--batch#${BAZEL_BOOT}\', \'--batch#" \
	configure.py)

	@${CP} ${PATCHDIR}/bazelrc ${WRKDIR}/bazelrc
	@${REINPLACE_CMD} "s#%%BAZEL_DIR%%#${WRKDIR}#" ${WRKDIR}/bazelrc
	@${REINPLACE_CMD} "s#%%BAZEL_DIST%%#${WRKDIR}#" ${WRKDIR}/bazelrc
	@${REINPLACE_CMD} "s#%%LOCALBASE%%#${LOCALBASE}#" ${WRKDIR}/bazelrc \
		${WRKSRC}/tensorflow/tensorflow.bzl ${WRKSRC}/.bazelrc \
		${WRKSRC}/tensorflow/core/BUILD \
		${WRKSRC}/third_party/systemlibs/protobuf.bzl

do-configure:
	(cd ${WRKSRC} && ${SETENV} \
		PYTHON_BIN_PATH=${PYTHON_CMD} \
		PYTHON_LIB_PATH="${PYTHON_SITELIBDIR}" \
		TF_NEED_JEMALLOC=0 \
		TF_NEED_KAFKA=0 \
		TF_NEED_OPENCL_SYCL=0 \
		TF_NEED_AWS=0 \
		TF_NEED_GCP=0 \
		TF_NEED_HDFS=0 \
		TF_NEED_S3=0 \
		TF_ENABLE_XLA=0 \
		TF_NEED_GDR=0 \
		TF_NEED_VERBS=0 \
		TF_NEED_OPENCL=0 \
		TF_NEED_MPI=0 \
		TF_NEED_TENSORRT=0 \
		TF_NEED_NGRAPH=0 \
		TF_NEED_IGNITE=0 \
		TF_NEED_ROCM=0 \
		TF_NEED_CUDA=0 \
		TF_SET_ANDROID_WORKSPACE=0 \
		TF_DOWNLOAD_CLANG=0 \
		TF_NEED_NCCL=0 \
		TF_NEED_OPENCL=0 \
		TF_IGNORE_MAX_BAZEL_VERSION=1 \
		CC_OPT_FLAGS="-I${LOCALBASE}/include" \
		PREFIX="${LOCALBASE}" \
		TF_SYSTEM_LIBS="absl_py astor_archive boringssl com_github_googleapis_googleapis com_github_googlecloudplatform_google_cloud_cpp com_google_protobuf \
				com_google_protobuf_cc com_googlesource_code_re2 curl cython double_conversion enum34_archive flatbuffers gast_archive gif_archive \
				grpc hwloc icu jpeg jsoncpp_git keras_applications_archive lmdb nasm nsync org_sqlite pasta pcre png_archive protobuf_archive \
				six_archive snappy swig termcolor_archive wrapt zlib_archive" \
		./configure)

do-build:
	(cd ${WRKSRC} && \
		bazel --bazelrc="${WRKDIR}/bazelrc" ${BAZEL_BOOT} build ${BAZEL_COPT} --host_copt="-I${LOCALBASE}/include" \
		--host_linkopt="-L${LOCALBASE}/lib" --linkopt="-L${LOCALBASE}/lib" --config=opt \
		--incompatible_no_support_tools_in_action_inputs=false \
		--verbose_failures \
		//tensorflow:libtensorflow.so \
		//tensorflow:libtensorflow_cc.so \
		//tensorflow:install_headers \
		//tensorflow/tools/pip_package:build_pip_package)

	(cd ${WRKSRC} && ${SETENV} TMPDIR=${WRKDIR} \
		bazel-bin/tensorflow/tools/pip_package/build_pip_package \
		${WRKDIR}/whl)

do-install:
	@${MKDIR} ${STAGEDIR}/${PYTHON_SITELIBDIR}
	@${MKDIR} ${WRKDIR}/tmp
	@${UNZIP_NATIVE_CMD} -d ${WRKDIR}/tmp ${WRKDIR}/whl/${PORTNAME}-${PORTVERSION}-*.whl
	@${FIND} ${WRKDIR}/tmp -name "*.so*" | ${XARGS} ${STRIP_CMD}
	cd ${WRKDIR}/tmp && ${COPYTREE_SHARE} ${PORTNAME}-${PORTVERSION}.dist-info \
		${STAGEDIR}${PYTHON_SITELIBDIR}
	cd ${WRKDIR}/tmp/${PORTNAME}-${PORTVERSION}.data/purelib && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.post.mk>
