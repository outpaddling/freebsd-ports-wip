# Do not upgrade this port before testing the new version with biology/py-qiime

PORTNAME=	swarm
PORTVERSION=	1.2.19
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Robust and fast clustering method for amplicon-based studies

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		shebangfix
SHEBANG_FILES=	scripts/*

USE_GITHUB=	yes
GH_ACCOUNT=	torognes

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/swarm \
		bin/amplicon_contingency_table.py \
		bin/swarm_breaker.py

.include <bsd.port.mk>
