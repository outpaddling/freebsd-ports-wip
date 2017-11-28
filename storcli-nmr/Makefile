# Created by: Hiroshi Fujishima <h-fujishima@sakura.ad.jp>
# $FreeBSD$

PORTNAME=	storcli
PORTVERSION=	1.05.45
CATEGORIES=	wip sysutils
MASTER_SITES=	http://www.lsi.com/downloads/Public/Nytro/downloads/Nytro%20XM/Management%20Software%20and%20Tools/NMR%201.7/
PKGNAMESUFFIX=	nmr
DISTNAME=	StorCLI-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	MegaRAID comand-line management utiliity

RESTRICTED=	Source recipient must acknowledge license. Reproduction or redistribution prohibited. See http://www.lsi.com/Pages/user/eula.aspx

ONLY_FOR_ARCHS= i386 amd64

USE_ZIP=        yes
NO_BUILD=       yes

PLIST_FILES=    sbin/storcli-${PKGNAMESUFFIX}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BASENAME=storcli
.elif ${ARCH} == "amd64"
BASENAME=storcli64
.endif

do-extract:
	${MKDIR} ${WRKSRC}
	(cd ${WRKSRC} && ${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
	(cd ${WRKSRC} && \
		${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} storcli_FreeBSD.zip)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BASENAME} \
		${STAGEDIR}${PREFIX}/sbin/storcli-${PKGNAMESUFFIX}

.include <bsd.port.post.mk>
