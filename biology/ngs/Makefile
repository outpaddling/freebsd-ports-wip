# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	ngs
PORTVERSION=	1.3.0
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	NCBI NGS language bindings

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_JAVA=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ncbi

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${STAGEDIR}${PREFIX}

ALL_TARGET=	subdirs

MAKE_JOBS_UNSAFE=	yes

# Don't do this post-patch, since it modifies files with static patches.
# Be sure to update static patches only after patch, not any later stages.
pre-configure:
	${REINPLACE_CMD} -e 's|x86_64|amd64|g' ${WRKSRC}/*/setup/konfigure.perl
	${LN} -s ${WRKSRC}/ngs-sdk/ngs/unix/x86_64 ${WRKSRC}/ngs-sdk/ngs/unix/amd64

# Experiment with clean simple makefiles to replace custom build system
#pre-build:
#	for subdir in dispatch adapter; do \
#		${CP} ${FILESDIR}/Makefile-sdk-$$subdir \
#			${WRKSRC}/ngs-sdk/$$subdir/Makefile; \
#		${CP} ${FILESDIR}/Makefile-sdk-$$subdir.depend \
#			${WRKSRC}/ngs-sdk/$$subdir/Makefile.depend; \
#	done
#	for lang in c++ java python; do \
#		${CP} ${FILESDIR}/Makefile-sdk-$$lang \
#			${WRKSRC}/ngs-sdk/language/$$lang/Makefile; \
#		${CP} ${FILESDIR}/Makefile-sdk-$$lang.depend \
#			${WRKSRC}/ngs-sdk/language/$$lang/Makefile.depend; \
#	done

.include <bsd.port.mk>
