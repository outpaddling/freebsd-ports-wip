PORTNAME=	resistomeanalyzer
PORTVERSION=	0.0.0p20170111
CATEGORIES=	wip

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tool for analyzing the resistome of large metagenomic datasets
WWW=		https://github.com/cdeanj/resistomeanalyzer

# Actually unspecified, just pretending for poudriere
LICENSE=	PD

USES=		gmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	cdeanj
GH_TAGNAME=	cb854a743c6283c1cc7cd6cf88a7791f59120080

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/resistome

.include <bsd.port.mk>
