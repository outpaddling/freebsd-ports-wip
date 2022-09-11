PORTNAME=	gdc-download
PORTVERSION=	0.1
CATEGORIES=	wip ftp
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Download tool for GDC (Genomic Data Commons) data
WWW=		https://example.com

LICENSE=	BSD2CLAUSE
#LICENSE_FILE=	

RUN_DEPENDS=	bash:shells/bash \
		curl:ftp/curl

USES=		tar:xz

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gdc-download ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
