# Created by: Hiroshi Fujishima <h-fujishima@sakura.ad.jp>
# $FreeBSD$

PORTNAME=	storcli
PORTVERSION=	1.04.07
CATEGORIES=	wip sysutils
MASTER_SITES=	http://www.lsi.com/downloads/Public/MegaRAID%20Common%20Files/
PKGNAMESUFFIX=	-mr
DISTNAME=	${PORTVERSION}_StorCLI

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	MegaRAID comand-line management utiliity

RESTRICTED=	Source recipient must acknowledge license. Reproduction or redistribution prohibited. See http://www.lsi.com/Pages/user/eula.aspx

ONLY_FOR_ARCHS= i386 amd64

USE_ZIP=        yes
NO_BUILD=       yes
WRKSRC=		${WRKDIR}/FreeBSD

PLIST_FILES=    sbin/storcli${PKGNAMESUFFIX}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BASENAME=storcli
.elif ${ARCH} == "amd64"
BASENAME=storcli64
.endif

post-extract:
	(cd ${WRKSRC} && \
		${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} ${BASENAME}.zip)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BASENAME} \
		${STAGEDIR}${PREFIX}/sbin/storcli${PKGNAMESUFFIX}

.include <bsd.port.post.mk>
