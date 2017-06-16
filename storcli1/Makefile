# Created by: Hiroshi Fujishima <h-fujishima@sakura.ad.jp>
# $FreeBSD$

PORTNAME=	storcli
PORTVERSION=	1.04.07
CATEGORIES=	wip sysutils
MASTER_SITES=	http://www.lsi.com/downloads/Public/MegaRAID%20Common%20Files/
DISTNAME=	${PORTVERSION}_StorCLI

MAINTAINER=	bacon4000@gmail.com
COMMENT=	SAS MegaRAID FreeBSD StorCLI

RESTRICTED=	Source recipient must acknowledge license. Reproduction or redistribution prohibited. See http://www.lsi.com/Pages/user/eula.aspx

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

ONLY_FOR_ARCHS=	i386 amd64

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	sbin/storcli

pre-fetch:
	@${FETCH_BINARY} -o /dev/null http://www.lsi.com/magic.axd\?x=e\&file=${MASTER_SITES}${DISTNAME}

.include <bsd.port.pre.mk>
post-extract:
.if ${ARCH} == "i386"
	@cd ${WRKSRC}/FreeBSD && ${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} storcli.zip
.elif ${ARCH} == "amd64"
	@cd ${WRKSRC}/FreeBSD && ${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} storcli64.zip
.endif

do-install:
.if ${ARCH} == "i386"
		${INSTALL_PROGRAM} ${WRKSRC}/FreeBSD/storcli   ${PREFIX}/sbin/storcli
.elif ${ARCH} == "amd64"
		${INSTALL_PROGRAM} ${WRKSRC}/FreeBSD/storcli64 ${STAGEDIR}${PREFIX}/sbin/storcli
.endif
.include <bsd.port.post.mk>
