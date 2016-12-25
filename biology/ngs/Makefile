# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$
#
# TODO
# Patch build system to install examples-python.  See plist vs pkg-plist.

PORTNAME=	ngs
PORTVERSION=	2016.12.23
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	NCBI NGS language bindings

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_JAVA=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	1326b274f3cfd98e832c2d176c4746a86372ee77

# Old build system
#PORTVERSION=	1.3.0
#GH_ACCOUNT=	ncbi
#HAS_CONFIGURE=	yes
#CONFIGURE_ARGS+=--prefix=${STAGEDIR}${PREFIX}
# ALL_TARGET=	subdirs
# MAKE_JOBS_UNSAFE=	yes
# Don't do this post-patch, since it modifies files with static patches.
# Be sure to update static patches only after patch, not any later stages.
#pre-configure:
#	${REINPLACE_CMD} -e 's|x86_64|amd64|g' ${WRKSRC}/*/setup/konfigure.perl
#	${LN} -s ${WRKSRC}/ngs-sdk/ngs/unix/x86_64 ${WRKSRC}/ngs-sdk/ngs/unix/amd64
#post-stage:
#	${REINPLACE_CMD} -i '' -e 's|${STAGEDIR}||g' \
#		${STAGEDIR}${EXAMPLESDIR}/examples-java/Makefile

# New build system
MAKEFILE=	Makefile.simple

.include <bsd.port.mk>
