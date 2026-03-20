PORTNAME=	system-hardware-identification
DISTVERSION=	0.1.0-3
DISTVERSIONSUFFIX=	-g4f1953f
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Allow non-root users to obtain limited hardware info from dmidecode
WWW=		https://github.com/outpaddling/system-hardware-identification

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:devel/libxtend
RUN_DEPENDS=	dmidecode>0:sysutils/dmidecode

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

PLIST_FILES=	"@(,,4511) bin/system-hardware-identification"

.include <bsd.port.mk>
