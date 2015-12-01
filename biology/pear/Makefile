# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	pear
PORTVERSION=	0.9.6
CATEGORIES=	biology
MASTER_SITES=	http://sco.h-its.org/exelixis/web/software/pear/files/
PKGNAMESUFFIX=	-merger
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	jwbacon@tds.net
COMMENT=	Memory-efficient and highly accurate pair-end read merger

# LICENSE=	Creative commons

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/pearRM man/man1/pearRM.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pear ${STAGEDIR}${PREFIX}/bin/pearRM
	${CP} ${WRKSRC}/man/pear.1 ${WRKSRC}/man/pearRM.1
	${INSTALL_MAN} ${WRKSRC}/man/pearRM.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
