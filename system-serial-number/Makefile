PORTNAME=	system-serial-number
DISTVERSION=	0.1.0-2
DISTVERSIONSUFFIX=	-gb3ff615
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Allow non-root user to obtain system serial number via dmidecode
WWW=		https://example.com/system-serial-number

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:devel/libxtend
RUN_DEPENDS=	dmidecode>0:sysutils/dmidecode

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

PLIST_FILES=	"@(,,4511) bin/system-serial-number"

.include <bsd.port.mk>
