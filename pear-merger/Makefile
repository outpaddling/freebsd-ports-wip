# $FreeBSD$

PORTNAME=	pear
# When the website is back up PORTVERSION=	0.9.8
PORTVERSION=	0.9.6
CATEGORIES=	wip biology
# MASTER_SITES=	http://sco.h-its.org/exelixis/web/software/pear/files/
# Not really redistributable.  Set up for manual download of newer versions
# via free academic checkout
MASTER_SITES=	https://depot.galaxyproject.org/software/pear/
PKGNAMESUFFIX=	-merger
DISTNAME=	${PORTNAME}_${PORTVERSION}_src_all

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Memory-efficient and highly accurate pair-end read merger

# Not sure about the specific flavor of Creative Commons
LICENSE=	CC0-1.0

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src

PLIST_FILES=	bin/pearRM man/man1/pearRM.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pear ${STAGEDIR}${PREFIX}/bin/pearRM
	${CP} ${WRKSRC}/man/pear.1 ${WRKSRC}/man/pearRM.1
	${INSTALL_MAN} ${WRKSRC}/man/pearRM.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
