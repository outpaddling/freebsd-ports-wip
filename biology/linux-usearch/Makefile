# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	usearch
PORTVERSION=	9.2.64
CATEGORIES=	biology
MASTER_SITES=	# empty
PKGNAMEPREFIX=	linux-
DISTNAME=	usearch9.2.64_i86linux32
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Extreme high-throughput sequence analysis

# Fix this later
LICENSE=	PD

RESTRICTED=	You must download manually from http://www.drive5.com/usearch/download.html

NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} bin/${DISTFILES}

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTFILES} ${STAGEDIR}${PREFIX}/bin
	${LN} ${STAGEDIR}${PREFIX}/bin/${DISTFILES} \
		${STAGEDIR}${PREFIX}/bin/usearch

.include <bsd.port.mk>
