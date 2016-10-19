USE_LDCONFIG=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
MAKE_CMD=	bjam
MAKEFILE=	#
MAKE_FLAGS=	#
ALL_TARGET=	stage
USES+=		compiler:features

PLIST_SUB+=	BOOST_SHARED_LIB_VER=${PORTVERSION} COMPAT_LIB_VER=5

PKG_MESSAGE_FILE_THREADS=	${PORTSDIR}/devel/boost-all/pkg-message.threads
PKG_MESSAGE_FILE_PYTHON=	${PORTSDIR}/devel/boost-all/pkg-message.python

MAKE_ARGS=	--layout=system \
		--prefix=${PREFIX} \

# Our compiler-flags will be added AFTER those set by bjam. We remove
# the optimization level, because Boost sets it itself (to -O3 in case
# of gcc/g++):
MAKE_ARGS+=    cxxflags="${CXXFLAGS:N-O*}" cflags="${CFLAGS:N-O*}"

BOOST_TOOLSET=	${CHOSEN_COMPILER_TYPE}

MAKE_ARGS+=	--toolset=${BOOST_TOOLSET} \
		${_MAKE_JOBS}

VERBOSE_BUILD_VARS=	MAKE_ARGS+=-d2

DEBUG_VARS=	MAKE_ARGS+=debug
DEBUG_VARS_OFF=	MAKE_ARGS+=release

MAKE_ARGS+=	threading=multi \
		link=shared,static

MAKE_ARGS+=	optimization=speed
OPTIMIZED_CFLAGS_VARS=	MAKE_ARGS+=inlining=full

# ccache build fails when using precompiled headers, on a cached build.
#
# base gcc 4.2.1 fails when using precompiled headers and running with a
# recent FreeBSD 11 kernel
MAKE_ARGS+=	pch=off

post-patch:
.if defined(USE_BINUTILS)
	@${ECHO} "using ${BOOST_TOOLSET} : : ${CXX} : <linkflags>-B${LOCALBASE}/bin ;" >> ${WRKSRC}/tools/build/src/user-config.jam
.else
	@${ECHO} "using ${BOOST_TOOLSET} : : ${CXX} ;" >> ${WRKSRC}/tools/build/src/user-config.jam
.endif
