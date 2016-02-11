# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$
# FIXME: Is there a way to use USE_GITHUB with gist repos?

PORTNAME=	fastunique
PORTVERSION=	2016.02.08
CATEGORIES=	biology
MASTER_SITES=	https://gist.github.com/meren/
DISTNAME=	abd5c6f014da9aa554a4/archive/dff6b4528a905500810d7a9048e617f8b80b0f77

MAINTAINER=	jwbacon@tds.net
COMMENT=	Sort and uniq fasta files

#LICENSE=	unspecified

USES=		python zip

WRKSRC=		${WRKDIR}/abd5c6f014da9aa554a4-dff6b4528a905500810d7a9048e617f8b80b0f77

NO_BUILD=	yes

PLIST_FILES=	bin/fastaunique

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fastaunique ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
