PORTNAME=	fastaunique
PORTVERSION=	0.0.0p20160208
CATEGORIES=	wip biology
MASTER_SITES=	https://gist.github.com/meren/abd5c6f014da9aa554a4/archive/
DISTNAME=	dff6b4528a905500810d7a9048e617f8b80b0f77

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Sort fasta files and eliminate duplicate lines

LICENSE=	NONE

USES=		python shebangfix zip
SHEBANG_FILES=	fastaunique

WRKSRC=		${WRKDIR}/abd5c6f014da9aa554a4-dff6b4528a905500810d7a9048e617f8b80b0f77

NO_BUILD=	yes

PLIST_FILES=	bin/fastaunique

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fastaunique ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
