PORTNAME=	ipmi-gather
DISTVERSION=	0.0.0-9
CATEGORIES=	wip net

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Collect IPMI info from inaccessible remote hosts
WWW=		https://github.com/outpaddling/ipmi-gather

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:devel/libxtend libmunge.so:security/munge

USE_GITHUB=	yes
USE_RC_SUBR=	ipmi_gather

USERS=		ftp
GROUPS=		${USERS}

GH_ACCOUNT=	outpaddling
GH_TAGNAME=	83e993162f798d144bcace5b3c29369da1f3ba45

PLIST_FILES=	bin/ipmi-gather bin/ipmi-send \
		"@dir(ftp,ftp,755) var/log/ipmi-gather"

.include <bsd.port.mk>
