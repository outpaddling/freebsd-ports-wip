
PORTNAME=	makedepf90
PORTVERSION=	2.8.9
CATEGORIES=	wip

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Generate include dependencies for Fortran code

LICENSE=	GPLv3

USES=		autoreconf gmake tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	bf704d72d56974f64e462511721b79fd22ec2048

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

ALL_TARGET=	makedepf90
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/makedepf90 man/man1/makedepf90.1.gz

pre-build:
	make depend

.include <bsd.port.mk>
