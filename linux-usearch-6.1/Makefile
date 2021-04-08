PORTNAME=	usearch
PORTVERSION=	6.1.544
CATEGORIES=	wip biology
MASTER_SITES=	# http://drive5.com/usearch/
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}_i86linux32
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Extreme high-throughput sequence analysis

# Fix this later
LICENSE=	PD

USES=		linux

RESTRICTED=	Redistribution is not permitted in any form

NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}61

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTFILES})
IGNORE=	because of licensing restrictions, you must manually download\
	${DISTFILES} from http://www.drive5.com/usearch/download.html,\
	place it in ${DISTDIR}, and run make again
.endif

# Using binary names assumed by qiime 1.9.1
do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTFILES} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}61

.include <bsd.port.post.mk>
