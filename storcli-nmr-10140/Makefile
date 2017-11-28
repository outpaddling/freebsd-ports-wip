# Created by: Hiroshi Fujishima <h-fujishima@sakura.ad.jp>
# $FreeBSD$

PORTNAME=	storcli
PORTVERSION=	1.01.40
CATEGORIES=	wip sysutils
MASTER_SITES=	http://www.lsi.com/downloads/Public/Nytro/downloads/Nytro%20XM/Management%20Software%20and%20Tools/
PKGNAMESUFFIX=	nmr
DISTNAME=	StorCLI%20Patch1%20-%20${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	MegaRAID comand-line management utiliity

RESTRICTED=	Source recipient must acknowledge license. Reproduction or redistribution prohibited. See http://www.lsi.com/Pages/user/eula.aspx

ONLY_FOR_ARCHS= i386 amd64

USE_ZIP=        yes
NO_BUILD=       yes

PLIST_FILES=    sbin/storcli-${PKGNAMESUFFIX}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BASENAME=StorCli
.elif ${ARCH} == "amd64"
BASENAME=StorCli64
.endif

do-extract:
	${MKDIR} ${WRKSRC}
	(cd ${WRKSRC} && ${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
	(cd ${WRKSRC}/FreeBSD && \
		${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} \
		MR_SAS_CLI_StorCLI-1.01.40.zip)
	(cd ${WRKSRC}/FreeBSD && \
		${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} \
		${BASENAME}.zip)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/FreeBSD/${BASENAME} \
		${STAGEDIR}${PREFIX}/sbin/storcli-${PKGNAMESUFFIX}

.include <bsd.port.post.mk>
