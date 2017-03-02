# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	usearch
PORTVERSION=	9.2.64
CATEGORIES=	biology
MASTER_SITES=	# http://drive5.com/usearch/
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}_i86linux32
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Extreme high-throughput sequence analysis

# Fix this later
LICENSE=	PD

USES=		linux

RESTRICTED=	Redistribution is not permitted in any form

NO_BUILD=	yes

PLIST_FILES=	bin/${DISTFILES}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTFILES})
IGNORE=	because of licensing restrictions, you must manually download\
	${DISTFILES} from http://www.drive5.com/usearch/download.html,\
	place it in ${DISTDIR}, and run make again
.endif

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTFILES} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
