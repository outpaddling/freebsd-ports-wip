# Created by: Hiroshi Fujishima <h-fujishima@sakura.ad.jp>
# $FreeBSD$

PORTNAME=	storcli
PORTVERSION=	1.01.75
CATEGORIES=	sysutils
MASTER_SITES=	http://www.lsi.com/downloads/Public/Nytro/downloads/Nytro%20XM/Management%20Software%20and%20Tools/NMR%201.5/
PKGNAMESUFFIX=	nmr
DISTNAME=	Storcli_FreeBSD_10175

MAINTAINER=	jwbacon@tds.net
COMMENT=	MegaRAID comand-line management utiliity

RESTRICTED=	Source recipient must acknowledge license. Reproduction or redistribution prohibited. See http://www.lsi.com/Pages/user/eula.aspx

ONLY_FOR_ARCHS= i386 amd64

USE_ZIP=        yes
NO_BUILD=       yes
WRKSRC=		${WRKDIR}/storcli_all_os

PLIST_FILES=    sbin/storcli-${PKGNAMESUFFIX}

FETCH_ARGS=	-F

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
	(cd ${WRKSRC} && \
		${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} ${BASENAME}.zip)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BASENAME} \
		${STAGEDIR}${PREFIX}/sbin/storcli-${PKGNAMESUFFIX}

.include <bsd.port.post.mk>
