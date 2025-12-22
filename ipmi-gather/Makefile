PORTNAME=	ipmi-gather
DISTVERSION=	0.0.0-13
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
GH_TAGNAME=	63ad1a5ed4f2214fe3a44f5dbec7b021619e9e55

# Until the kinks are worked out
WITH_DEBUG=	yes

PLIST_FILES=	bin/ipmi-gather bin/ipmi-send \
		"@dir(ftp,ftp,755) var/log/ipmi-gather"

.include <bsd.port.mk>
