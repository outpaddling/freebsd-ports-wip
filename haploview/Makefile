PORTNAME=	haploview
PORTVERSION=	4.1
CATEGORIES=	wip biology java
MASTER_SITES=	http://www.broad.mit.edu/ftp/pub/mpg/haploview/
DISTNAME=	Haploview_${PORTVERSION}.jar
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Common interface to tasks relating to haplotype analyses

#LICENSE=	https://www.broadinstitute.org/haploview/contact-and-support

NO_WRKSUBDIR=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.7+

NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	haploview.sh
SUB_LIST=	JARNAME=${DISTNAME}

PLIST_FILES=	bin/haploview ${JAVAJARDIR:C,${PREFIX}/?,,}/${DISTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/haploview.sh \
		${STAGEDIR}${PREFIX}/bin/haploview

.include <bsd.port.mk>
