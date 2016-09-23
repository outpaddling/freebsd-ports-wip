# Created by: Alexander Churanov <churanov.port.maintainer@gmail.com>
# $FreeBSD: head/devel/boost-libs/Makefile 418153 2016-07-06 22:10:14Z mat $

PORTNAME=	boost-libs

COMMENT=	Free portable C++ libraries (without Boost.Python)

BUILD_DEPENDS+=	bjam:/usr/wip/devel/boost-jam

OPTIONS_DEFINE=		VERBOSE_BUILD DEBUG OPTIMIZED_CFLAGS
OPTIONS_MULTI=		LOCALE
OPTIONS_MULTI_LOCALE=	ICONV ICU
OPTIONS_DEFAULT=	ICONV ICU
VERBOSE_BUILD_DESC=	Show compiler messages
ICONV_DESC=		Boost.Locale with iconv encoding support
ICU_DESC=		Boost.Regex/Locale with ICU unicode support

ICONV_USES=		iconv
ICONV_VARS=		MAKE_ARGS+=-sICONV_PATH=${ICONV_PREFIX}
ICONV_VARS_OFF=		MAKE_ARGS+=boost.locale.iconv=off
ICU_LIB_DEPENDS=	libicuuc.so:devel/icu
ICU_VARS=		MAKE_ARGS+=-sICU_PATH=${LOCALBASE}
ICU_VARS_OFF=		MAKE_ARGS+=boost.locale.icu=off

.include "${.CURDIR}/../boost-all/common.mk"

.include "${.CURDIR}/../boost-all/compiled.mk"

MAKE_ARGS+=    --without-python
ALL_TARGET=    stage

post-build:
	@cd ${WRKSRC}/stage/lib && \
		( for l in lib*.so.*; do ${LN} -sf $${l} $${l%.${PORTVERSION}}.5; done )

do-install:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} --prefix=${STAGEDIR}${PREFIX} ${MAKE_ARGS:NDESTDIR=*} install
# For some reasons BJAM forget about the links
	@cd ${WRKSRC}/stage/ && ${FIND} lib -type l | ${PAX} -rw -p p ${STAGEDIR}${PREFIX}

# display pkg-message
post-install:
	@${TOUCH} ${PKGMESSAGE}

	@${CAT} ${PKG_MESSAGE_FILE_THREADS} >> ${PKGMESSAGE}
	@${ECHO_CMD} >> ${PKGMESSAGE}

	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

	@${REINPLACE_CMD} \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e "s|%%PYTHON_INCLUDEDIR%%|${PYTHON_INCLUDEDIR}|g" \
		-e "s|%%PYTHON_LIBDIR%%|${PYTHON_LIBDIR}|g" \
		-e "s|%%PYTHON_VERSION%%|${PYTHON_VERSION}|g" ${PKGMESSAGE}

.include <bsd.port.mk>
